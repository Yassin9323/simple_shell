#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;


char *_reader (void);
char **_tokenizer(char *line);
int _executer(char **tokens, char **argv, int x);
void _free_memory(char **array);

/* Hande Env  , Path , Error */
char *_getenv(char *variable);
char *_handlepath(char *tokens);
void dis_errors(char *name, char *com, int x );
void reverse_string(char *str, int len);
char *int_to_asci(int n);




#endif
