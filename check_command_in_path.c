#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "shell.h"

#define MAX_PATH_LENGTH 1024
#define INITIAL_BUFFER_SIZE 64

/**
 * The function checks if a given command is present in the system's PATH environment variable.
 *
 * @param command A string representing the command to be checked in the PATH directories.
 *
 * @return an integer value. It returns 1 if the command is found in one of the directories specified
 * in the PATH environment variable and is executable (has execute permission), and it returns 0
 * otherwise.
 */
int check_command_in_path(char *command)
{
    char *path = getenv("PATH");
    if (path == NULL)
    {
        return 0;
    }

    char *dir;
    while ((dir = get_path_dir(path)) != NULL)
    {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
        if (access(full_path, X_OK) == 0)
        {
            return 1;
        }
    }

    return 0;
}

