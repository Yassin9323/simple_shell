#include "shell.h"

int main(void)
{
    char *token= NULL;
    size_t buffer = 0 ;
    char *line = NULL;
    char *del = ' ';
    char *input;

    printf("Enter Command : ");
   input= getline(&line, &buffer, stdin);
                printf(" line is :  %s\n ", line);
                	free(line);

                printf(" line is :  %s\n ", line);


token = strtok(line, del);

	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = strtok(NULL, del);
	}
	

return 0;
	
}
