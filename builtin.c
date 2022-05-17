/*
* Author: Rodrigo Zarate & Ronal Aguirre
* Date: may 2022
*/

#include "hsh.h"

int _ownexit(char **argv);
int xd(void);
int _printenv(void);
int _owncd(char **argv);

/**
 * _own - select own implementations
 * @argv: char double pointer
 * Return: int code for builtin
 */
int _own(char **argv)
{
	int builtin = NOTFOUND;
	char *task = argv[0];

	if (_strncmp(task, "exit", _strlen("exit")) == 0)
		builtin = _ownexit(argv);
	else if (_strncmp(task, "XD", _strlen("XD")) == 0)
		builtin = xd();
	else if (_strncmp(task, "env", _strlen("env")) == 0)
		builtin = _printenv();
	else if (_strncmp(task, "cd", _strlen("cd")) == 0)
		builtin = _owncd(argv);

	return (builtin);
}

/**
 * _ownexit - quit
 * @argv: args
 * Return: 1, 2
 */
int _ownexit(char **argv)
{
	int status, holder;
	int *p_status = &initvars()->p_status;

	status = BREAK;
	if (argv[1])
	{
		if (_isdigit(argv[1]))
		{
			holder = _atoi(argv[1]);
			*p_status = holder;
			if (holder >= 0)
				return (BREAK);
		}
		_printerror(2, argv[1]);
		*p_status = 2;
		status = CONTINUE;
	}
	return (status);
}

/**
 * _printenv - print env vars
 * Return: CONTINUE
 */
int _printenv(void)
{
	int i;

	if (environ)
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
	return (CONTINUE);
}

/**
 * xd - just smile
 * Return: 0
 */
int xd(void)
{
	printf("--------------------------\n");
	printf("-X---------X---DDDDDD-----\n");
	printf("---X-----X-----D------D---\n");
	printf("-----X-X-------D-------D--\n");
	printf("------X--------D-------D--\n");
	printf("-----X-X-------D-------D--\n");
	printf("---X-----X-----D------D---\n");
	printf("-X---------X---DDDDDDD----\n");
	printf("--------------------------\n ");

	return (0);
}

/**
 * _owncd - change directory
 * @argv: double pointer
 * Return: int
 */
int _owncd(char **argv)
{
	int *p_status = &initvars()->p_status;
	char *actdir = get_env_var("PWD");
	char *home = get_env_var("HOME");
	char *prevdir = get_env_var("OLDPWD");
	char *newcd = argv[1];
	char *hold;
	int builtin = CONTINUE;
	int flag = 0;
	*p_status = 0;

	if (!newcd || *newcd == '~' ||
		_strncmp(newcd, "$HOME", _strlen("$HOME")) == 0)
		newcd = home;
	else if (_strncmp(newcd, "-", _strlen("-")) == 0)
	{
		flag = 1;
		newcd = prevdir;
	}
	if (newcd)
	{
		builtin = chdir(newcd);
		if (builtin != -1)
			_strcpy(actdir, newcd);
		else
		{
			_printerror(3, newcd);
			*p_status = 2;
		}
	}
	if (flag)
	{
		hold = getcwd(NULL, 0);
		printf("%s\n", hold);
		free(hold);
	}
	return (builtin);
}
