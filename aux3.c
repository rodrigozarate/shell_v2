/*
* Author: Rodrigo Zarate & Ronal Aguirre
* Date: may 2022
*/

#include "hsh.h"

/**
 * parseline - parse input line
 * @str: input
 * Return: char double pointer
 */
char **parseline(char *str)
{
	char **liststr;
	char *copystr, *tempstr;
	char const *breaker = " \t";
	int i, n;

	if (!str)
		return (NULL);
	
	copystr = _strdup(str);
	if (!copystr)
		return (NULL);
	
	tempstr = copystr;
	n = 0;
	while (strtok(tempstr, breaker))
	{
		n++;
		tempstr = NULL;
	}
	free (copystr);
	if (n == 0)
		return (NULL);
	
	liststr = malloc(sizeof(*liststr) * (n + 1));
	if (!liststr)
		return (NULL);
	
	tempstr = str;
	for (i = 0; i < n; i++)
	{
		liststr[i] = strtok(tempstr, breaker);
		tempstr = NULL;
	}
	liststr[i] = NULL;

	return (liststr);
}
