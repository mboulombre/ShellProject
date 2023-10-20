#include <stdio.h>
#include <stdlib.h>

#define READ_SIZE 8

static char buffer[READ_SIZE];
static int offset = 0;

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
char *buf = buffer + offset;
size_t bufsize = READ_SIZE - offset;
if (bufsize == 0)
{
offset = 0;
buf = buffer;
bufsize = READ_SIZE;
}
int c;
size_t i = 0;
while ((c = fgetc(stream)) != EOF)
{
if (i >= bufsize)
{
bufsize += READ_SIZE;
*lineptr = realloc(*lineptr, bufsize);
if (!*lineptr)
{
return (-1);
}
buf = *lineptr + bufsize - READ_SIZE;
}
buf[i++] = c;
if (c == '\n')
{
break;
}
}
buf[i] = '\0';
if (bufsize - i < READ_SIZE)
{
offset = bufsize - i;
memcpy(buffer, buf + i, offset);
}
else
{
offset = 0;
}
*n = bufsize;
return (i);  
}
