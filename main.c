#include "shell.h"

int main (int argc, char **argv)
{
	char *line = NULL;
	char **comm = NULL;	
	int status = 0;
	(void) argc;
	
	(void) comm;
	
	while(1)
	{
		line = _reader();
			if(line == NULL)		 /*this mean EOF by (ctrl + D) 
			{
				if(isatty(STDIN_FILENO)) 	
						write(STDOUT_FILENO, "\n", 1); 	*/
					return (status);
			
				
/*
		comm = _tokenizer(line);

		status = _executer(comm, argv);

*/
			tokenizer(line, " ");

			printf("%s", argv[0]);
				
		

	}




	return (0);
}
