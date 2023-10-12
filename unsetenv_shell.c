#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * The function `unsetenv_shell` unsets an environment variable in a shell.
 * 
 * @name The parameter "name" is a pointer to a string that represents the name of the
 * environment variable that we want to unset.
 * 
 * @return an integer value. If the unsetenv function is successful (returns 0), then the function will
 * return 0. If the unsetenv function fails (returns a non-zero value), then the function will return
 * -1.
 */
int unsetenv_shell(const char *name)
{
if (unsetenv(name) != 0)
{
perror("unsetenv");
return -1; 
}
return 0; 
}
