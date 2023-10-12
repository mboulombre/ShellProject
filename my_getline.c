#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

ssize_t my_getline(char **lineptr, size_t *n) {
    ssize_t nread;

    if ((nread = getline(lineptr, n, stdin)) == -1) {
        return -1;
    }

    // Remove comments by replacing # and everything after with a null terminator
    for (ssize_t i = 0; i < nread; i++) {
        if ((*lineptr)[i] == '#') {
            (*lineptr)[i] = '\0';
            nread = i;
            break;
        }
    }

    return nread;
}
