#include <stdio.h>
#include <unistd.h>

/**
 * main - fork function
 *
 * Return: Always 0.
 */
int main(void)
{
pid_t parent_pid;
pid_t child_pid;
child_pid = fork();
if (child_pid == -1)
{
perror("Error:");
return (1);
}
parent_pid = getpid();
printf(" pid is %u\n", parent_pid);
if (child_pid == 0)
{
printf("(%u)\n", parent_pid);
}
else
{
printf("(%u) %u, parent\n", parent_pid, child_pid);
}
return (0);
}
