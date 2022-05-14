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
