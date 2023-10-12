#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "shell.h"

// Function to execute a command with ||
int execute_command_or(const char *command)
{
    // Split the command and arguments
    char *arg = strchr(command, ' ');
    if (arg != NULL)
    {
        *arg = '\0'; // Null-terminate the command
        arg++;       // Move to the next character after the space
    }

    // Check if the command exists in PATH before forking
    if (!check_command_in_path(command))
    {
        printf("%s: command not found\n", command);
        return -1; // Command not found
    }

    // Create a child process
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return -1; // Fork failed
    }

    if (pid == 0)
    {
        // Child process
        // Execute the command with arguments using execvp
        if (execlp(command, command, arg, NULL) == -1)
        {
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    }
}

