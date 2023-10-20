#include <stdio.h>
#include <string.h>

char *find_path(char **args, char **env)
{
char *path, *token, *cmd;
int len = 0;
path = getenv("PATH");
if (!path)
return (NULL);
len = strlen(args[0]);
cmd = malloc(len + 1);
memcpy(cmd, args[0], len);
cmd[len] = '\0';
token = strtok(path, ":");
while (token)
{
strcpy(cmd, token);
strcat(cmd, "/");
strcat(cmd, args[0]);
if (access(cmd, F_OK) == 0) 
return (cmd);
token = strtok(NULL, ":");
}
return (NULL);  
}
