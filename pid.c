#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
pid_t me_pid;
me_pid = getpid();
printf("%u\n", me_pid);
return (0);
}
