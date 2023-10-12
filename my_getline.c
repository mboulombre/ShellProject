#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

size_t my_getline(char **lineptr, size_t *n)
{
    static char buffer[INITIAL_BUFFER_SIZE];
    static size_t buffer_size = INITIAL_BUFFER_SIZE;
    static size_t buffer_position = 0;
    ssize_t chars_read = 0;

    if (*n < buffer_size)
    {
        *n = buffer_size;
    }

    if (*lineptr == NULL)
    {
        *lineptr = malloc(buffer_size);
        if (*lineptr == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }

    while (1)
    {
        char c = getchar();
        if (c == EOF || c == '\n')
        {
            if (chars_read == 0)
            {
                return -1; // No more input
            }
            (*lineptr)[chars_read] = '\0'; // Null-terminate the line
            return chars_read;
        }

        (*lineptr)[chars_read] = c;
        chars_read++;

        if (chars_read >= buffer_size - 1)
        {
            buffer_size *= 2;
            *lineptr = realloc(*lineptr, buffer_size);
            if (*lineptr == NULL)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }
    }
}

