#include <stdio.h>
#include "shell.h"

int shell_env(char **args, char **env)
{
int i;
for (i = 0; env[i] != NULL; i++)
printf("%s\n", env[i]);
return (1);
}
