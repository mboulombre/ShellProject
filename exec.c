#include <stdio.h>
#include <unistd.h>

/**
 * main - exec function
 *
 * Return: Always 0.
 */
int main(void)
{
char *argv[] = {"ls", "-l", NULL};
char *env[] = {"NULL"};
if (execve("/usr/bin/ls", argv, env) == -1)
{
perror("Error:");
}
return (0);
}
