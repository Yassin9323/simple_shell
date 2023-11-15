#include "shell.h"

int main (int ac, char **argv)
{
	char *line =NULL;
	char **tokens = NULL;
	int status = 0;
	int x = 0;
    (void) ac;

	
	while(1)
	{
		line = read_line();
			if(line == NULL)		
			{
				if(isatty(STDIN_FILENO)) 	
						write(STDOUT_FILENO, "\n", 1); 
				return (status);
			}
		
		tokens = _tokenizer(line);
		if(!tokens)
			continue;

	
		status = _executer(tokens, argv, x);		
	}
}
