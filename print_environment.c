#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * The function "print_environment" prints all the environment variables.
 */
void print_environment()
{
char **env = environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}
