#include "hsh.h"

/**
 * initvars - inital variables stored in structure
 * Return: pointer
 */
initvars_t *initvars(void)
{
	static initvars_t initial_vars;

	return (&initial_vars);
}