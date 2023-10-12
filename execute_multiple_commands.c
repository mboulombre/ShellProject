#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "shell.h"
// Function to execute multiple commands separated by ;
void execute_multiple_commands(char *commands)
{
    char *token = strtok(commands, ";");
    while (token != NULL)
    {
        int status = execute_command(token);
        // Print the status, if needed
        printf("Command executed with status: %d\n", status);
        token = strtok(NULL, ";");
    }
}
