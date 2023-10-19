#include <stdio.h>
#include <stdlib.h>

/*
 * _getenv function
 *
 */
char *_getenv(const char *name)
{
extern char **environ;
int i;
char *tokent;
i = 0;
while (environ[i])
token = strtok(environ[i], "=");
if (strcmp(token, name) == 0)
{
return (strtok(NULL, "="));
}
i++;
}

void main(void)
{
char *homevale = _getenv("HOME");
printf("%s\n", homevale);
}
