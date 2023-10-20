#include <stdio.h>
#include <string.h>
#include "shell.h"

void shell_loop(int ac, char **av, char **env) 
{

char *line;
char **args;
char *path;
int status;

do {
printf("> ");
line = read_line();
args = split_line(line);
if (args[0] == NULL)
{
continue;

}
if (strcmp(args[0], ENV) == 0)
{
status = shell_env(args, env);
}
else
{
path = find_path(args, env);
if (path)
{
status = execute(args, env);
}
else
{

printf("Command not found\n");
status = 1;
}

}  
free(line);
free(args);
} while (status);
}


