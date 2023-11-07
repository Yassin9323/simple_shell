#include "shell.h"

int main (int argc, char **argv)
{
	char *line;
	char **tokens;
	int status = 0;
	int i;
	int count = 0;
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
				

		for (i = 0; tokens[i] != NULL; i++)
		{
			printf("Token %d: %s\n", i, tokens[i]);
		}

		for (i = 0; i < count; i++)
			free(tokens[i]);
		
		free(tokens);
		free(line);

		count++;
		
	}




	return (0);
}
