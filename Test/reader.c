#include "shell.h"

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
		return (NULL);
	}

	return (line);

}
