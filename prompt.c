#include <stdio.h>
#include <stdlib.h>
/**
 * main - prompt function
 *
 * Return: Always 0.
 */
int main(void)
{
size_t n = 0;
char *buff = NULL;
printf("root@2502699e4b1b$");
getline(&buff, &n, stdin);
printf("%s", buff);
free(buff);
return (0);
}
