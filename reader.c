#include "shell.h"
char *read_line(void)
{
	char *line = NULL;										/* store the input from user            ---            read by getline */
	size_t len = 0;											/* keep track on buffer size --- dynamic allocated --- read by getline */
	ssize_t n;												/* store the number of characters          ---         read by getline */

	if(isatty(STDIN_FILENO))								/* Handle new line for active and non active mood */
			write(STDOUT_FILENO, "$ ", 2);					/* make new line and put this sign $ when run hsh */
	n = getline(&line, &len, stdin);
	
	if(n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);

}
