#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "shell.h"

/**
* The function "exist_shell" is used to exit the shell with a specified status.
*
* @param status represents the exit status of the shell.
* Check whether the shell terminated successfully or encountered an error.
* A value of 0 usually indicates successful termination
* While non-zero values indicate an error or
* abnormal termination.
*/
void exit_shell(int status)
{
exit(status);
}
