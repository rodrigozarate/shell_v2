#include "hsh.h"

int _ownsetenv(char **argv)
{
	int status;

	if(argv[1] && argv[2])
	{
		printf("VAR: %s CONTENT: %s", argv[1], argv[2]);
		/* append node to the end of environment */
		/* walk envar until end */
		/* set end to point to new mem adress */
	}
	else
	{
		printf("Wrong use, missing argument");
	}
	status = CONTINUE;
	
	return (status);
}

int _ownunsetenv(char **argv)
{
	int status;

	if(argv[1])
	{
		printf("Try to unset VAR: %s", argv[1]);
		/* check if var exists */
		/* delete node */
		/* reconnect the nodes */
	}
	else
	{
		printf("Wrong use, missing argument");
	}
	status = CONTINUE;

	return (status);
}
