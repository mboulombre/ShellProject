#ifndef _SHELL_H_
#define _SHELL_H_

#define EXIT "exit"
#define ENV "env"
char *read_line(void);
char **split_line(char *line);
void shell_loop(int ac, char **av, char **env);
char *read_line(void);
char **split_line(char *line);
int execute(char **args, char **env);  
char *find_path(char **args, char **env);
int shell_exit(char **args);
int shell_env(char **args, char **env);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *line, const char *delim);

#endif
