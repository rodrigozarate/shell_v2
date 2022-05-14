#include "hsh.h"
int direct(char const *str);

char *cmdselect(char *cmd)
{
	char *realpath = NULL;
	/* path_t *places = NULL, *driver; */
	char *revcmd;
	/* int len, status; */

	if (cmd == NULL || *cmd == '\0')
		return (NULL);

	revcmd = cmd;
	if (!direct(revcmd) && access(revcmd, X_OK) == 0)
		return (revcmd);
	
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
