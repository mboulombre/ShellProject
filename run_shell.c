
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

void run_shell(const char *filename)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    FILE *input = stdin;

    if (filename != NULL)
    {
        input = fopen(filename, "r");
        if (input == NULL)
        {
            perror("fopen");
            return;
        }
    }

    while ((nread = getline(&line, &len, input)) != -1)
    {
        // Remove comments by replacing # and everything after with a null terminator
        for (ssize_t i = 0; i < nread; i++)
        {
            if (line[i] == '#')
            {
                line[i] = '\0';
                nread = i;
                break;
            }
        }

        if (nread == 0)
        {
            continue; // Empty line or comment, skip
        }

        // Execute commands
        execute_multiple_commands(line);
    }

    if (line)
    {
        free(line);
    }

    if (input != stdin)
    {
        fclose(input);
    }
}

int main(int argc, char *argv[])
{
    // Get the shell process ID for the $$ variable
    shell_pid = getpid();

    if (argc > 1)
    {
        run_shell(argv[1]); // Execute commands from the file
    }
    else
    {
        run_shell(NULL); // Interactive mode
    }

    return 0;
}

