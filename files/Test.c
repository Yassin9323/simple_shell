
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

int main (int argc, char **argv)
{
	char *line;
	char **tokens;
	int status = 0;
	int i;
	(void) argv;
	(void) argc;
	
	
	while(1)
	{
		line = _reader();
			if(line == NULL)		 /*this mean EOF by (ctrl + D) 
			{
				if(isatty(STDIN_FILENO)) 	
						write(STDOUT_FILENO, "\n", 1); 	*/
					return (status);

		tokens = _tokenizer(line);
		if(!tokens)
			continue;
				

		for (i = 0; tokens[i] != NULL; i++)
		{
			printf("Token %d: %s\n", i, tokens[i]);
			free(tokens[i]) , tokens[i] = NULL;
		}			
		
		free(tokens), tokens = NULL;		
	}




	return (0);
}





char **_tokenizer(char *line)
{
	char **tokens = malloc(sizeof(char*));
	char *del = " ";
	char *token ;
	int count = 0;
	size_t len ;
	char *tmp = NULL;
	int x = 0 ; 
	if(!line)
			return (NULL);
	
	/*		New Edit for realloc	 */
	tmp = strdup(line);
	token = strtok(tmp, del);
	if (token == NULL)
	{
		free(line) , line = NULL;
		free(tmp) , tmp = NULL;

	}
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
		
		tokens[x] = strdup(token);
		token = strtok(NULL, " ");
		x++;
	}
	free(line);
	free(token);
	tokens[x] = NULL;

	return (tokens);

}


char *_reader (void)
{
	char *line = NULL;										/* store the input from user            ---            read by getline */
	size_t buffer = 0;											/* keep track on buffer size --- dynamic allocated --- read by getline */
	ssize_t nn;												/* store the number of characters          ---         read by getline */

	if(isatty(STDIN_FILENO))								/* Handle new line for active and non active mood */
			write(STDOUT_FILENO, "$ ", 2);					/* make new line and put this sign $ when run hsh */
	nn = getline(&line, &buffer, stdin);

	if(nn == -1)
	{
		free(line);
		perror("Error reading input");
		return (NULL);
	}

	return (line);

}
