#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void exec(char **argv);
char *get_location(char *command);

/*string headers*/
int _strlen(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
int _strcmp(char *s1, char *s2);

void _fork(char **argv);

void _exits();
#endif
