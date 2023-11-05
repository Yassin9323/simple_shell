#include "shell.h"

void tokenizer(char *line, char *delim)
{
	char *token;

	token = strtok(line, delim);

	while (token != NULL)
	{
		printf("Token: %s", token);
		token = strtok(NULL, delim);
	}
}
