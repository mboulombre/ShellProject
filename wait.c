#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & waitfunction
 *
 * Return: Always 0.
 */
int main(void)
{
pid_t child_pid;
int status;
child_pid = fork();
if (child_pid == -1)
{
perror("Error:");
return (1);
}
if (child_pid == 0)
{
printf("Loading\n");
sleep(3);
}
else
{
wait(&status);
printf(" it's ok now\n");
}
return (0);
}
