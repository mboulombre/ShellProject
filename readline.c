#include "shell.h"

char *read_line(void)
{
char *line = NULL;
size_t n = 0;
_getline(&line, &n, stdin);
return (line);

}
