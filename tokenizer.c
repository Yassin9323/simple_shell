#include "shell.h"

char **_tokenizer(char *line)
{
	char **tokens = malloc(sizeof(char*));
	char *del = " ";
	char *token ;
	int count = 0;
	size_t len ;
	

	if (tokens == NULL)
	{
		perror("Memory allocation error");
		exit(1);
	}

	 len = strlen(line);
	if (len > 0 && line[len-1] == '\n')
			line[len-1] = '\0';

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
