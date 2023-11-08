#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;


char *_reader (void);
char **_tokenizer(char *line);
int _executer(char **tokens, char **argv);
void _free_memory(char **array);


#endif
