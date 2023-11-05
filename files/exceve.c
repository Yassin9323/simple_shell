#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
	size_t n ;
	char *buff = NULL;

	printf("Enter Command ");
	getline(&buff, &n, stdin);
	printf("The Command is :  %s\n ",buff);
	free(buff);

	char *com[] = {"/bin/ls", "-l", NULL};
	int val = execve(com[0], com, NULL);
	if (val == -1)
		perror("Error");

	printf("Done with execve \n");

	return 0;
}	
