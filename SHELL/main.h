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
char *search_in_current_directory(const char *command);
char *search_in_path(const char *command);

/*string headers*/
int _strlen(const char *s);
void _puts(char *str);
char *_strcpy(char *dest, const char *src);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
char* _strchr(const char* str, int character);


void _fork(char **argv);

void _exits();

void _environ(char **env);
#endif
