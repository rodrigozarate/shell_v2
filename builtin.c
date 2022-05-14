/*
* Author: Rodrigo Zarate & Ronal Aguirre
* Date: may 2022
*/

#include "hsh.h"

int xd(void);
int _printenv(void);

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
 * XD - just smile
 * Return: 0
 */
int xd(void)
{
	printf("Just, SMILE!\n \nXD\n\n ");
	return (0);
}
