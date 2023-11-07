#include "shell.h"

char **_tokenizer(char *line)
{
	char **tokens = malloc(sizeof(char*));
	char *del = " ";
	char *token;
	int count = 0;

	if (tokens == NULL)
	{
		perror("Memory allocation error");
		exit(1);
	}

	token = strtok(line, del);

	while (token)
	{
		tokens = realloc(tokens, (count + 1) * sizeof(char*));
		if (tokens == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
		tokens[count] = strdup(token);
		token = strtok(NULL, " ");
		count++;
	}

	tokens[count] = NULL;

	return (tokens);

}
