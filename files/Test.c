#include "shell.h"

int main(void)
{
	char *del = ' ';
	char *token = NULL;
	size_t buffer = 0;
	char *line = NULL;

	printf("Enter Command : \n");
	getline(&line, &buffer, stdin);

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

	return 0;
}
