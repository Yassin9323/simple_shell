#include "shell.h"

char **_tokenizer(char *line)
{
	char **tokens = malloc(sizeof(char*));
	char *del = " ";
	char *token ;
	int count = 0;
	size_t len ;
	char *tmp = NULL;
	int x = 0 ; 

	if (tokens == NULL)
	{
		perror("Memory allocation error");
		exit(1);
	}
	/*		New Edit for realloc	 */
	tmp = strdup(line);
	token = strtok(tmp, del);
	while(token)
	{
			count++;
			token = strtok(NULL, del);
	}
	free(tmp);
	tokens = malloc(sizeof (char *) * (count + 1 ));

	if(!tokens)
	{
	free(line);
	return (NULL);
	}
	
	/*		Handle Last Space In String 	*/
	 len = strlen(line);
	if (len > 0 && line[len-1] == '\n')
			line[len-1] = '\0';

	token = strtok(line, del);


	while (token)
	{
		if (tokens == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
		tokens[x] = strdup(token);
		token = strtok(NULL, " ");
		x++;
	}

	tokens[x] = NULL;

	return (tokens);

}
