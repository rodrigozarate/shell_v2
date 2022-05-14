/*
* Author: Rodrigo Zarate & Ronal Aguirre
* Date: may 2022
*/

#include "hsh.h"

/**
 * _isdigit - validate if data is digit
 * @tocheck: char pointer
 * Return: 1
 */
int _isdigit(const char * const tocheck)
{
	int i;
	const char *driver = tocheck;

	if (*driver == '-')
		driver++;

	for (i = 0; driver[i]; i++)
		if (driver[i] < '0' || driver[i] > '9')
			return (0);

	return (1);
}

/**
 * _atoi - returns the converted integral number as an int value.
 * If no valid conversion could be performed, it returns zero
 * @tocheck: char pointer
 * Return: int or  0
 */
int _atoi(char *tocheck)
{
	int i = 0;
	int n = 0;
	int s = 1;

	if (tocheck[0] == '-')
	{
		s = -1;
		i++;
	}

	while (tocheck[i])
	{
		n = n * 10 + tocheck[i] - '0';
		i++;
	}

	return (s * n);
}

/**
 * _printerror - print error
 * @errorcode: list of main errors
 * @argv: arg vector
 * Return: 0
 */
int _printerror(int errorcode, char *argv)
{
	const char *error_list[] = {
		"ALL FINE",
		"%s: %d: %s: not found\n",
		"%s: %d: exit: Illegal number%s\n",
		NULL
	};

	fprintf(stderr, error_list[errorcode],
			initvars()->p_name,
			initvars()->p_tasks,
			argv);

	return (0);
}
