#include "shell.h"

int main (int argc, char **argv)
{
	char *line = NULL;
	char *comm = NULL;	
	int status = 0;
	(void) argc;
		(void) argv;

	
	
	while(1)
	{
		line = _reader();
			if(line == NULL)		 /*this mean EOF by (ctrl + D) 
			{
				if(isatty(STDIN_FILENO)) 	
						write(STDOUT_FILENO, "\n", 1); 	*/
					return (status);
			free(line);
				

		comm = _tokenizer(line);
		printf("comm is : %s\n", comm);
		
/*
		status = _executer(comm, argv);

		_tokenizer(line, " ");

			printf("%s", argv[1]);
				

*/
			
		

	}




	return (0);
}
