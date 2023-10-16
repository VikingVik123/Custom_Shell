#include "main.h"

void _environ(char **env)
{
    /*Iterate through the environment variables and print them*/
    	int i = 0;
	while (env[i] != NULL)
	{
		 _puts(env[i]);
		 i++;
	}
}
