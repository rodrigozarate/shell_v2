#ifndef _HSH_HOLBERTON_
#define _HSH_HOLBERTON_

#define PROMPT "(XD): "

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

/**
 * struct initvars_s - startup vars
 * @p_name: argv[0]
 * @p_status: The status code
 * @p_tasks: How many task to be done
 */
typedef struct initvars_s
{
	char *p_name;
	int p_status;
	int p_tasks;
} initvars_t;

initvars_t *initvars(void);

/**
 * enum CONSTANTS - constants
 * @BREAK: break
 * @CONTINUE: continue
 */
enum CONSTANTS
{
	SUCCESS,
	BREAK,
	CONTINUE
};

#endif /* _HSH_HOLBERTON_ */