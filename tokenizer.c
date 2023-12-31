#include "shell.h"
char **_tokenizer(char *line)
{
	char **tokens = NULL;
	char *tmp = NULL;
	char *token =NULL;
	size_t len ;
	int count = 0;
	int x = 0 ; 
	if(!line)
		return (NULL);
	
	/*New Edit for realloc*/
	tmp = strdup(line);
	token = strtok(tmp, DEL);
	if (token == NULL)
	{
		free(line) , line = NULL;
		free(tmp) , tmp = NULL;
		return(NULL);
	}
	while(token)
	{
			count++;
			token = strtok(NULL, DEL);
	}
	free(tmp), tmp = NULL;
	tokens = malloc(sizeof (char *) * (count + 1 ));

	if(!tokens)
	{
	free(line), line = NULL;
	return (NULL);
	}
	/*Handle Last Space In String*/
	 len = strlen(line);
	if (len > 0 && line[len-1] == '\n')
		line[len-1] = '\0';

	token = strtok(line, DEL);

	while (token)
	{
		tokens[x] = strdup(token);
		token = strtok(NULL, DEL);
		x++;
	}
	free(line), line = NULL;
	tokens[x] = NULL;

	return (tokens);
}
