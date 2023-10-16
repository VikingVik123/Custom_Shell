#include "main.h"

void exec(char **argv)
{
	char *command = NULL;
	char *actual_command = NULL;

	if (argv)
	{
		command = argv[0];
		actual_command = get_location(command);

		if (execve(actual_command, argv, NULL) == -1)
		{
			free(actual_command);
			perror("Error:");
			_exits();
		}
		free(actual_command);
	}
}
