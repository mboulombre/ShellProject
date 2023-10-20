#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int execute(char **args, char **env)
{
pid_t pid;
int status;
pid = fork();
if (pid == 0)
{
if (execve(args[0], args, env) == -1)
{
perror("shell");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("shell");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}
