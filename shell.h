#ifndef SHELL_H
#define SHELL_H
#define MAX_COMMAND_LENGTH 100

void run_shell();
int check_command_in_path(char *command);
void exit_shell(int status);
void print_environment();
size_t my_getline(char **lineptr, size_t *n);
int setenv_shell(const char *name, const char *value, int overwrite);
int unsetenv_shell(const char *name);
int cd_shell(const char *directory); // New prototype for cd
int execute_command(const char *command)
#endif /* SHELL_H */

