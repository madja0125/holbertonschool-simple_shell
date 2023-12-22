#include "sshell.h"

/**
 * main - Entry point for the shell.
 * @argc: Argument count.
 * @argv: Argument vector.
 * @env: Enviroment variables.
 *
 * Return: Status code.
*/
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	
	/* Check if in interactive mode */
	if (isatty(STDIN_FILENO))
	prompt();

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (read > 0 && line[read - 1] == 0)
		line[read -1] = '\0';
		
		if (is_empty(line))
		{
			if (isatty(STDIN_FILENO))
			prompt();
			continue;
		}

		execute(line);

		if (isatty(STDIN_FILENO))
		prompt();
	}

	if (read == -1)
	putchar('\n');

	free(line);
	return (EXIT_SUCCESS);
}
