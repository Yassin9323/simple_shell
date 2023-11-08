#include "shell.h"

int main (int argc, char **argv)
{
	char *line;
	char **tokens;
	int status = 0;
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

		status = _executer(tokens, argv);	
				

		
		
				
	}




	return (0);
}
