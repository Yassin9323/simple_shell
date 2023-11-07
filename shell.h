#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>



char *_reader (void);
void _printf(char *string, int descriptor);
char **_tokenizer(char *line);



#endif
