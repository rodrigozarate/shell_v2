#ifndef _HSH_HOLBERTON_
#define _HSH_HOLBERTON_

#define PROMPT "(XD): "

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
 * struct path_s - list of paths
 * @pathstring: the path
 * @next: more paths
 */
typedef struct path_s
{
	char *pathstring;
	struct path_s *next;
} path_t;

/**
 * enum CONSTANTS - constants
 * @SUCCESS: 0
 * @BREAK: 1 break
 * @CONTINUE: 2 continue
 * @NOTFOUND: 3 notfound
 */
enum CONSTANTS
{
	SUCCESS,
	BREAK,
	CONTINUE,
	NOTFOUND
};

/* driver */
void driver(char **argv);
int read_line(char **line, size_t *n);
int launch(char **input, char **argv);
int execute(char const *cmd, char *const *args);

/* builtin */
int _own(char **argv);
int _ownexit(char **argv);

/* cmdselect */
char *cmdselect(char *cmd);
void freelist(path_t *head);
int getpath(path_t **head);
void freelist(path_t *head);
path_t *addnode(path_t **head, char *pvalue);

/* aux 1 */
int _isdigit(const char * const tocheck);
int _atoi(char *tocheck);
int _printerror(int errorcode, char *argv);
/* aux 2 */
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(const char *tocheck);
char *_strdup(const char *string);
char *_strcpy(char *scopy, const char *sorigin);
/* aux 3 */
char **parseline(char *str);
char *get_env_var(const char *theenv);

#endif /* _HSH_HOLBERTON_ */
