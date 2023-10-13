#include "main.h"

int main(int ac, char **av)
{

    char *lineptr;
    char *lineptr_cpy = NULL;
    const char *delim = " \n";
    size_t n = 0;
    char *token;
    ssize_t line = 0;
    int num_token = 0;
    int i = 0;
    int j = 0;
    char **argv;
    char *prompt;
    (void)ac;
    (void)av;

    prompt = ":$ ";

	while (1)
	{
		

		printf("%s", prompt);
		line = getline(&lineptr, &n, stdin);
		lineptr_cpy = malloc(sizeof(char) * line);

		if (line == -1)
             	{
			free(lineptr);
			lineptr = NULL;
			break;
                }
		
		if (lineptr_cpy == NULL)
		{
			perror("tsh: memory allocation error");
			free(lineptr_cpy);

			lineptr_cpy = NULL;
			break;
		}
		

		_strcpy(lineptr_cpy, lineptr);
		token = strtok(lineptr, delim);
		
		while (token != NULL)
		{
			num_token++;
			token = strtok(NULL, delim);
		}
		
		num_token++;
			
		argv = malloc(sizeof(char *) * num_token);
		token = strtok(lineptr_cpy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			_strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		
        	argv[i] = NULL;

		if (strcmp(argv[0], "exit") == 0)
			_exits();
		
		_fork(argv);

		for (j = 0; j < num_token; j++)
                {
                        free(argv[j]);
                }

                free(argv);
                free(lineptr_cpy);

        }
        free(lineptr);
        return (0);
}

