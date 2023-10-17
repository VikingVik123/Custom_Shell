#include "main.h"

/**
 * exec - function to execute commands
 * @argv: argument vector
 * return: void
 */

void exec(char **argv)
{
	
    if (argv)
    {
        char *command = argv[0];
        
        /* Check if the command contains a full path*/
        if (_strchr(command, '/') != NULL)
        {
            if (execve(command, argv, NULL) == -1)
            {
                perror("Error:");
                _exits();
            }
	   
        }
        else
        {
            char *actual_command = search_in_path(command);

            if (actual_command == NULL)
            {
                /* Command not found in PATH*/
                perror("Not found");
                _exits();
            }

            if (execve(actual_command, argv, NULL) == -1)
            {
                perror("Error:");
                _exits();
            }
            free(actual_command);
        }
    }
}

