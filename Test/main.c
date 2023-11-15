#include "shell.h"

int main (int ac, char **argv)
{
	char *line = NULL;
	char **tokens = NULL;
	int status = 0, x = 0;
	(void) ac;
	
	while(1)
	{
		line = _reader();
			if(line == NULL)		 /*this mean EOF by (ctrl + D) */
			{
				if(isatty(STDIN_FILENO)) 	
						write(STDOUT_FILENO, "\n", 1); 	
				return (status);
			}
		x++;
		tokens = _tokenizer(line);
		if(!tokens)
			continue;

		 

		status = _executer(tokens, argv, x);			
	}
}
