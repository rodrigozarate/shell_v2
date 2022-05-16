/*
* Author: Rodrigo Zarate & Ronal Aguirre
* Date: may 2022
*/

#include "hsh.h"

/**
 * _strncmp - compare strings
 * @s1: first string
 * @s2: compare string
 * @n: maximum number of characters to be compared
 * Return: 0 if equal, < 0 if s1 is minor > 0 if s2 is minor
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i + 1 < n)
		i++;
	return (s1[i] - s2[i]);
}

/**
 * _strlen - return the lenght of string
 * @tocheck: string to check
 * Return: lenght of tocheck
 */
int _strlen(const char *tocheck)
{
	size_t i;

	i = 0;
	while (tocheck[i])
		i++;
	return (i);
}

/**
 * _strdup - duplicate string
 * @string: input
 * Return: pointer
 */
char *_strdup(const char *string)
{
	int lenght;
	char *newstr;

	lenght = 0;
	while (string[lenght])
		lenght++;

	newstr = malloc(sizeof(*newstr) * (lenght + 1));
	if (!newstr)
		return (NULL);

	for (lenght = 0; string[lenght]; lenght++)
		newstr[lenght] = string[lenght];
	newstr[lenght] = '\0';

	return (newstr);
}

char *_strcpy(char *scopy, const char *sorigin)
{
	int i;

	for (i = 0; sorigin[i]; i++)
		scopy[i] = sorigin[i];
	scopy[i] = '\0';

	return (scopy);
}
