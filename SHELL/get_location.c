#include "main.h"

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
    	int command_length, directory_length;
    	struct stat buffer;


        path = getenv("PATH");
        /*Duplicate of path*/
        path_copy = strdup(path);

        command_length = strlen(command);

        path_token = strtok(path_copy, ":");

        while(path_token != NULL)
        {
            /* Get the length of the directory*/
            directory_length = strlen(path_token);
            /* allocate memory for storing the command name together with the directory name */
            file_path = malloc(command_length + directory_length + 2);

            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);
            strcat(file_path, "\0");

            if (stat(file_path, &buffer) == 0)
            {
                /* return value of 0 means success implying that the file_path is valid*/

                /* free up allocated memory before returning your file_path */
                free(path_copy);

                return (file_path);
            }
            else
            {

                /* free up the file_path memory so we can check for another path*/
                free(file_path);
                path_token = strtok(NULL, ":");

            }

         }
	 free(path_copy);
        

        /* before we exit without luck, let's see if the command itself is a file_path that exists */
        if (stat(command, &buffer) == 0)
        {
            return (command);
        }



        return (NULL);

}
