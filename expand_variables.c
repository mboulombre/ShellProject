#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

char *expand_variables(const char *input)
{
    char *expanded = (char *)malloc(strlen(input) * 2); // Ensure enough space for expansion
    size_t i = 0;
    size_t j = 0;

    while (input[i] != '\0')
    {
        if (input[i] == '$')
        {
            if (input[i + 1] == '$')
            {
                // Replace $$ with the shell process ID
                int len = snprintf(expanded + j, 10, "%d", shell_pid);
                j += len;
                i += 2;
            }
            else if (input[i + 1] == '?')
            {
                // Replace $? with the last exit status
                int len = snprintf(expanded + j, 10, "%d", last_exit_status);
                j += len;
                i += 2;
            }
            else if (input[i + 1] == '{')
            {
                // Variable expansion
                size_t start = i + 2;
                while (input[i] != '\0' && input[i] != '}')
                {
                    i++;
                }
                if (input[i] == '}')
                {
                    char variable_name[128]; // Adjust the maximum variable name length as needed
                    memset(variable_name, 0, sizeof(variable_name));
                    strncpy(variable_name, input + start, i - start);
                    char *variable_value = getenv(variable_name);
                    if (variable_value != NULL)
                    {
                        strcpy(expanded + j, variable_value);
                        j += strlen(variable_value);
                    }
                    i++; // Move past the '}'
                }
            }
            else
            {
                // Not a variable or special expansion, copy as is
                expanded[j++] = input[i++];
            }
        }
        else
        {
            expanded[j++] = input[i++];
        }
    }

    expanded[j] = '\0';
    return expanded;
}

