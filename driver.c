/*
* Author: Rodrigo Zarate & Ronal Aguirre
* Date: may 2022
*/

#include "hsh.h"

/**
 * driver - Detect when to stop
 * @argv: Arguments
 */

void driver(char **argv)
{
	size_t n = 0;
	char *line = NULL;
	int bytes, d_status, *tsk_counter;

	tsk_counter = &initvars()->p_tasks;

	while (1)
	{
		(*tsk_counter)++;
		bytes = read_line(&line, &n);
		if (bytes == EOF)
			break;
		if (bytes == 1)
			continue;
		d_status = launch(&line, argv);
		if (d_status == BREAK)
			break;
		if (d_status == CONTINUE)
			continue;
	}
	free(line);
}

/**
 * read_line - read line
 * @line: from stdin
 * @n: size
 * Return: read size
 */
int read_line(char **line, size_t *n)
{
	int bytes;
	char *walk;

	if (isatty(STDIN_FILENO))
		printf("%s", PROMPT);
	
	bytes = getline(line, n, stdin);
	if (bytes == EOF)
	{
		if (isatty(STDIN_FILENO))
			puts("");
	}
	else
	{
		walk = *line;
		while (*walk)
		{
			if (*walk == '\n')
				*walk = '\0';
			walk++;
		}
	}
	return (bytes);
}

/**
 * launch - launch commands
 * @input: input
 * @argv: arguments vector
 * Return: p_status
 */
int launch(char **input, char **argv)
{
	char *line = *input;
	
	int status = SUCCESS, *p_status = &initvars()->p_status;

	(void) argv;
	printf(" - line: %s \n",line);
	printf(" - p_status: %d \n",*p_status);
	return (status);
}

/**
 * execute - execute task
 * @cmd: commands
 * @args: arguments
 * Return: 0
 */
int execute(char const *cmd, char *const *args)
{
	int status = 0;
	pid_t p_pid;

	p_pid = fork();
	if (p_pid == 0)
	{
		status = execve(cmd, args, environ);
		exit(status);
	}
	else
	{
		waitpid(p_pid, &status, 0);
		if (status)
			return (1);
	}
	return (0);
}
