#include "shell.h"

char *_tokenizer(char *line, char *del)
{
	char *token;
	token = strtok(line, del);


	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = strtok(NULL, del);
	}
	return token;
}
