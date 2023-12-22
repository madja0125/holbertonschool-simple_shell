#include "sshell.h"

/**
 * prompt - Function that prints prompt.
 * @void: No parameters needed.
*/

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$", 9);
}

/**
 * free_args - Function that frees memory.
 * @args: Array of strings to be freed.
*/
void free_args(char **args)
{
	int i;

	if (args == NULL)
	return;

	if (args != NULL)
	{
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
	}
	free(args);
}
