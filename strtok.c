#include <stdio.h>
#include <string.h>

char *_strtok(char *str, const char *delim)
{
static char *olds;
char *token;
if (str != NULL)

olds = str;
if (olds == NULL)
return (NULL);
token = olds;
while (*token != '\0')
{
if (strchr(delim, *token) == NULL)
break;
token++;

}
olds = token;
while (*olds != '\0')
{
if (strchr(delim, *olds) != NULL)
{
*olds = '\0';
olds++;
return (token);
}
olds++;
}
olds = NULL;
return (token);
}
