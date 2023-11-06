#include "shell.h"

char *_tokenizer(char *line)
{
	char *token;
	char del = ' ';



/*   Handle The Last Space in String  */
	size_t len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';



	token = strtok(line, &del);


	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = strtok(NULL, &del);
	}
	return token;
}
