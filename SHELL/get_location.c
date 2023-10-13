#include "main.h"

char *get_location(char *command)
{
	char *path_copy;
	char *path_token;
	struct stat buffer;

    char *path = getenv("PATH");
    if (path == NULL) 
    {
        return NULL; /* PATH environment variable not set */
    }

    path_copy = _strdup(path);
    if (path_copy == NULL)
    {
        return NULL; /* Memory allocation failed */
    }



    path_token = strtok(path_copy, ":");
    while (path_token != NULL)
    {
        size_t directory_length = _strlen(path_token);
        size_t command_length = _strlen(command);
        size_t file_path_length = directory_length + 1 + command_length + 1; /* +1 for '/' and +1 for '\0' */

        char *file_path = malloc(file_path_length);
        
	if (file_path == NULL)
	{
            free(path_copy);
            return NULL; /* Memory allocation failed */
        }

        _strcpy(file_path, path_token);
        _strcat(file_path, "/");
        _strcat(file_path, command);

        if (stat(file_path, &buffer) == 0) 
	{
            /* The file exists */
            free(path_copy); /* Free path_copy since you're returning file_path */
            return file_path;
        } else 
	{
            /*Free file_path before looping */
            free(file_path);
            path_token = strtok(NULL, ":");
        }
    }

    free(path_copy);

    /* If the command isn't found in any directory, check if it's a valid file in the current directory*/
    if (stat(command, &buffer) == 0) 
    {
        return _strdup(command); /* Return a duplicate, since you'll free this later */
    }

    return NULL; /*Command not found*/
}

