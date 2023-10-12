#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

// Implement the setenv built-in command
int setenv_shell(const char *name, const char *value, int overwrite)
{
if(overwrite || getenv(name) == NULL)
{
if(setenv(name, value, 1) != 0)
{
perror("setenv");
return -1; // Setenv failed
}
return 0; // Success
}
else
{
fprintf(stderr, "setenv: Variable '%s' already exists.\n", name);
return -1; // Failure
}
}

