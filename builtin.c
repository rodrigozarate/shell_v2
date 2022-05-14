#include "hsh.h"

/**
 * _own - select own implementations
 * @argv: char double pointer
 */
int _own(char **argv)
{
	int status = NOTFOUND;
	char *cmd = argv[0];
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
		perror(2, argv[1]);
		*p_status = 2;
		status = CONTINUE;
	}
	return (status);
}
