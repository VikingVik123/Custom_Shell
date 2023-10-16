#include "main.h"

int main(int ac, char **av, char **env)
{
    char *lineptr = NULL;
    char *lineptr_cpy = NULL;
    const char *delim = " \n";
    size_t n = 0;
    char *token;
    ssize_t line = 0;
    int num_token = 0;
    int i = 0;
    int j = 0;
    char **argv = NULL;
    char *prompt;
    (void)ac;
    (void)av;

    prompt = ":$ ";

    while (1)
    {
        _puts(prompt);
        line = getline(&lineptr, &n, stdin);

        if (line == -1)
        {
            _puts("EOF Detected\n");
            free(lineptr);
            lineptr = NULL;
            _exits();
        }
        else
        {
            lineptr_cpy = _strdup(lineptr);

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

            argv = malloc(sizeof(char *) * num_token + 1);

            if (argv == NULL)
            {
                perror("tsh: memory allocation error");
                free(lineptr_cpy);
                free(lineptr);
                _exits();
            }

            token = strtok(lineptr_cpy, delim);

            for (i = 0; token != NULL; i++)
            {
                argv[i] = malloc(sizeof(char) * _strlen(token) + 1);

                if (argv[i] == NULL)
                {
                    perror("tsh: memory allocation error");
                    for (j = 0; j < i; j++)
                    {
                        free(argv[j]);
                    }
                    free(argv);
                    free(lineptr_cpy);
                    free(lineptr);
                    _exits();
                }

                _strcpy(argv[i], token);
                token = strtok(NULL, delim);
            }

            argv[i] = NULL;

            if (argv[0] != NULL) /* Check if the command is not NULL */
            {
                if (_strcmp(argv[0], "printenv") == 0)
                {
                    _environ(env); /* Pass env to your print_environment function */
                }

                if (_strcmp(argv[0], "clear") == 0)
                {
                    system("clear");
                }

                if (_strcmp(argv[0], "exit") == 0)
                {
                    for (j = 0; j < num_token; j++)
                    {
                        free(argv[j]);
                    }
                    free(argv);
                    free(lineptr_cpy);
                    free(lineptr);
                    _exits();
                }

                _fork(argv);
            }
            else
            {
                /* Handle empty command here, if needed */
                for (j = 0; j < num_token; j++)
                {
                    free(argv[j]);
                }
                free(argv);
            }

            free(lineptr_cpy);
        }

	for (i = 0; i < num_token; i++)
        {
            free(argv[i]);
        }
        free(argv);
    }

    free(lineptr);
    return 0;
}

