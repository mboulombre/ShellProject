
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

void run_shell()
{
    char *command = NULL;
    size_t command_size = 0;
    char prompt[] = "simple_shell$ ";

    while (1)
    {
        printf("%s", prompt);

        ssize_t chars_read = my_getline(&command, &command_size);
        if (chars_read == -1)
        {
            // Handle end of file (Ctrl+D)
            printf("\n");
            break;
        }

        // Check if the command is "exit" or "env" (built-ins)
        if (strcmp(command, "exit") == 0)
        {
            // Check for arguments after "exit"
            char *arg = strchr(command, ' ');
            if (arg != NULL)
            {
                arg++; // Move to the next character after the space
                int exit_status = atoi(arg);
                exit_shell(exit_status);
            }
            else
            {
                exit_shell(EXIT_SUCCESS); // Default exit status
            }
        }
        else if (strcmp(command, "env") == 0)
        {
            print_environment();
            continue; // Skip forking if the command is "env"
        }
        else if (strncmp(command, "setenv", 6) == 0)
        {
            // Check for "setenv" command
            char *args = command + 7; // Move to the next character after "setenv"
            char *name = strtok(args, " ");
            char *value = strtok(NULL, " ");
            if (name != NULL && value != NULL)
            {
                setenv_shell(name, value, 1); // Overwrite existing variable
            }
            else
            {
                fprintf(stderr, "setenv: Invalid syntax. Usage: setenv VARIABLE VALUE\n");
            }
            continue; // Skip forking after setenv
        }
        else if (strncmp(command, "unsetenv", 8) == 0)
        {
            // Check for "unsetenv" command
            char *arg = command + 9; // Move to the next character after "unsetenv"
            if (arg != NULL)
            {
                unsetenv_shell(arg);
            }
            else
            {
                fprintf(stderr, "unsetenv: Invalid syntax. Usage: unsetenv VARIABLE\n");
            }
            continue; // Skip forking after unsetenv
        }
        else if (strncmp(command, "cd", 2) == 0)
        {
            // Check for "cd" command
            char *arg = command + 3; // Move to the next character after "cd"
            if (strcmp(arg, "-") == 0)
            {
                // Handle "cd -" to switch to the previous directory
                cd_shell(getenv("OLDPWD"));
            }
            else
            {
                cd_shell(arg);
            }
            continue; // Skip forking after cd
        }

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
            continue; // Skip forking if the command is not found
        }

        // Create a child process
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
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
        else
        {
            // Parent process
            int status;
            if (wait(&status) == -1)
            {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }
    }

    free(command);
}

int main()
{
    run_shell();
    return 0;
}
