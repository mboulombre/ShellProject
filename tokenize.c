#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#define TOK_BUFSIZE 64 
#define TOK_DELIM " \t\r\n\a"

char **_split_line(char *line)
{
int bufsize = TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;
if (!tokens)
{
fprintf(stderr, "Allocation error\n");
exit(EXIT_FAILURE);
}
token = _strtok(line, TOK_DELIM);
while (token != NULL)
{
tokens[position] = token;
position++;
if (position >= bufsize)
{
bufsize += TOK_BUFSIZE;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{
fprintf(stderr, "Allocation error\n");
exit(EXIT_FAILURE);
}
}
token  = _strtok(NULL, TOK_DELIM); 

}
tokens[position] = NULL;
return (tokens);
}
