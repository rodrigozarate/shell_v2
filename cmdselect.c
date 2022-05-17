#include "hsh.h"
int direct(char const *str);

/**
 * cmdselect - command selector
 * @cmd: command
 * Return: path
 */
char *cmdselect(char *cmd)
{
	char *realpath = NULL;
	path_t *places = NULL, *driver;
	char *revcmd;
	int length, status;

	if (cmd == NULL || *cmd == '\0')
		return (NULL);

	revcmd = cmd;
	if (!direct(revcmd) && access(revcmd, X_OK) == 0)
		return (revcmd);

	status = getpath(&places);
	if (status == 0)
	{
		driver = places;
		while (driver)
		{
			length = _strlen(driver->pathstring) + _strlen("/") + _strlen(revcmd);
			realpath = malloc(sizeof(*realpath) + (length + 1));
			_strcpy(realpath, driver->pathstring);
			if (*realpath != '\0')
				_strcpy(realpath + _strlen(realpath), "/");
			_strcpy(realpath + _strlen(realpath), revcmd);
			if (access(realpath, X_OK) == 0)
				break;
			free(realpath);
			realpath = NULL;
			driver = driver->next;
		}
		freelist(places);

	}
	free(revcmd);
	return (realpath);
}

/**
 * direct - task can be executed whitout path
 * @str: string
 * Return: 0 if OK, 1 if NULL, 2 if not found
 */
int direct(char const *str)
{
	int lenght;

	if (!str)
		return (1);
	lenght = _strlen(str);

	if (str[0] == '/')
		return (0);

	if (lenght < 2)
		return (1);

	if (str[0] == '.' && str[1] == '/')
		return (0);

	if (lenght < 3)
		return (1);

	if (str[0] == '.' && str[1] == '.' && str[2] == '/')
		return (0);

	return (2);
}

/**
 * getpath - list of path
 * @head: pointer to head
 * Return: 0 if ok
 */
int getpath(path_t **head)
{
	char *buffer, *driver, *pvalue;
	int bufsize, i, j;

	pvalue = get_env_var("PATH");
	if (!pvalue)
		return (1);

	bufsize  = _strlen(pvalue) + 1;

	buffer = malloc(sizeof(*buffer) * (bufsize));
	if (!buffer)
		return (2);

	driver = pvalue;
	for (i = j = 0; i < bufsize; i++)
	{
		buffer[j] = driver[i];
		if (driver[i] == '\0' || driver[i] == ':')
		{
			buffer[j] = '\0';
			addnode(head, buffer);
			j = 0;
			continue;
		}
		j++;
	}
	free(buffer);
	return (0);
}

/**
 * freelist - free list of paths
 * @head: the head
 */
void freelist(path_t *head)
{
	path_t *willi;

	if (!head)
		return;
	while ((willi = head) != NULL)
	{
		head = head->next;
		free(willi->pathstring);
		free(willi);
	}
}

/**
 * addnode - add node of paths
 * @head: the head
 * @pvalue: the path
 * Return: new node or NULL
 */
path_t *addnode(path_t **head, char *pvalue)
{
	char *copypth;
	path_t *node, *driver;

	node = malloc(sizeof(*node));
	copypth = _strdup(pvalue);
	node->pathstring = copypth;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	driver = *head;
	while (driver->next)
		driver = driver->next;
	driver->next = node;
	return (node);
}
