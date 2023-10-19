#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
size_t buff_size = 0;
char *buff = NULL;
char *token;
int status, i = 0;
char **array;
pid_t child_pid;
while (1)
{
write(1, "#cisfun$ ", 9);
getline(&buff, &buff_size, stdin);
token = strtok(buff, " \t\n");
array = (char **)malloc(sizeof(char *) * 1024);
while (token)
{
array[i] = token;
token = strtok(NULL, " \t\n");
i++;
}
array[i] = NULL;
child_pid = fork();
if (child_pid == -1)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
if (execvp(array[0], array) == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
i = 0;
free(array);
}
free(buff);
return (0)
}

