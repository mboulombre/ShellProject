#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "shell.h"
// Implement the cd built-in command
int cd_shell(const char *directory)
{
char *new_directory = (directory != NULL) ? strdup(directory) : getenv("HOME");
if (new_directory == NULL)
{
perror("cd");
return -1; // Failure
}

char *previous_directory = getcwd(NULL, 0);
if (previous_directory == NULL)
{
perror("cd");
free(new_directory);
return -1; // Failure
}

if (chdir(new_directory) != 0)
{
perror("cd");
free(new_directory);
free(previous_directory);
return -1; // Failure
}

if (setenv("PWD", new_directory, 1) != 0)
{
perror("setenv");
free(new_directory);
free(previous_directory);
return -1; // Failure
}

free(new_directory);
free(previous_directory);
return 0; // Success
}

