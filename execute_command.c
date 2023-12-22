#include "sshell.h"

/**
 * execute - function that takes a an user input en executes it
 * @line: user input
 * Return: void
 */

void execute(char *line)
{
	char **args;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		setenv("LC_ALL", "C", 1);
		
		args = parse_arguments(line);
		execvp(args[0], args);
		perror(args[0]);
		free_args(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
