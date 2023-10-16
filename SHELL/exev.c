#include "main.h"

/**
 * exec - function to execute commands
 * @argv: argument vector
 * return: void
 */

void exec(char **argv)
{
	char *command = NULL;
	char *actual_command = NULL;

	if (argv)
	{
		command = argv[0];
		actual_command = search_in_path(command);

		if (execve(actual_command, argv, NULL) == -1)
		{
			free(actual_command);
			perror("Error:");
			_exits();
		}
		free(actual_command);
	}
}
