#ifndef SSHELL_H
#define SSHELL_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <ctype.h>

/* main */
int main(void);

/* Shell User line functions */
void prompt(void);
void execute(char *line);
char **parse_arguments(char *line);
void free_args(char **args);
int check_for_builtins(char *command, char **args);
int is_empty(const char *str);
char *search_executable_in_path(const char *executable);
void prompt(void);


#endif
