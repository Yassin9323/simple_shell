#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;


char *_reader (void);
char **_tokenizer(char *line);
int _executer(char **tokens, char **argv, int x);
void _free_memory(char **array);

/* Hande Env  , Path , Error */
char *_getenv(char *variable);
char *_handlepath(char *tokens);
void dis_errors(char *name, char *com, int x );
void reverse_string(char *str, int len);
char *int_to_asci(int n);


int main (int argc, char **argv)
{
	char *line;
	char **tokens;
	int status = 0, x = 0;
	(void) argc;
	
	while(1)
	{
		line = _reader();
			if(line == NULL)		 /*this mean EOF by (ctrl + D) 
			{
				if(isatty(STDIN_FILENO)) 	
						write(STDOUT_FILENO, "\n", 1); 	*/
					return (status);
		x++;
		tokens = _tokenizer(line);
		if(!tokens)
			continue;

		

		status = _executer(tokens, argv, x);			
	}
}



void dis_errors(char *name, char *com, int x )
{
    char *input;
    char mssg[] = ": not found\n";
    input = int_to_asci(x);

    write(STDERR_FILENO, name, strlen(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, input, strlen(input));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, com, strlen(com));
    write(STDERR_FILENO, mssg, strlen(mssg));

    free(input);

}


/* Convert from Integer to ascii */
char *int_to_asci(int n)
{
    char buffer[20];
    int i = 0 ; 

    if (n == 0 )
        buffer[i++] = '0';

    else 
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10 ) + '0';
            n/= 10 ;
        }
    }
    buffer[i] = '\0';
    reverse_string(buffer, i);

    return (strdup(buffer));
}
void reverse_string(char *str, int len)
{

    char tmp ;
    int start = 0 ;
    int end = len -1;

    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}

char *_getenv(char *variable)
{
    char *tmp, *key, *value, *env;
    int i;

    for(i = 0; environ[i]; i++)
    {
        tmp = strdup(environ[i]);
        key = strtok(tmp, "=");
        if (strcmp(key , variable) == 0 )
        {
            value = strtok(NULL, "\n");
            env = strdup(value);
            free (tmp);
            return (env);
        }
    free(tmp);
    tmp = NULL;
    }
    return (NULL);
}
#include "shell.h"

int _executer(char **tokens, char **argv, int x)
{
    pid_t test;
    int status ;
    char *full_command;

    full_command = _handlepath(tokens[0]);
    if (!full_command)
    {
        dis_errors(argv[0], tokens[0], x);
        _free_memory(tokens);
        return(127);
    }

    test = fork();

    if(test == 0 ) /* Child process */
    {
           if (execve(full_command, tokens, environ) == -1 )
            {
                     free(full_command), full_command = NULL;
                     _free_memory(tokens);
            }
    }
    else
    {
        waitpid(test, &status, 0);
        _free_memory(tokens);
        free(full_command), full_command = NULL;

    }

    return (WEXITSTATUS(status));
}

void _free_memory(char **array)
{
    int x;

    if(!array)
        return ; 

    for (x = 0; array[x]; x++)
    {
        free(array[x]);
        array[x] = NULL;
    }
    
    free(array), array = NULL;
    
}

char *_handlepath(char *tokens)
{

char *path_env, *full_command, *directory;
struct stat st;
int i;

for (i = 0; tokens[i]; i++)
{
    if (tokens[i] == '/')
    {
        if(stat(tokens, &st) == 0)
            return (strdup(tokens));

        return (NULL);    
    }
}
path_env = _getenv("PATH");
/* Handle Unset path */
if (!path_env)
    return(NULL);

directory = strtok(path_env, ":");
while(directory)
{
    full_command = malloc(strlen(directory) + strlen(tokens) + 2 );
    if(full_command)
    {
        strcpy(full_command, directory);
        strcat(full_command, "/");
        strcat(full_command, tokens);
        if (stat(full_command, &st) == 0)
        {
            free(path_env);
            return (full_command);
        }
    free(full_command);
    full_command = NULL;

    directory = strtok(NULL, ":");

    }

}
    free(path_env);
    return (NULL);
}
/*
int main (int ac, char **av){

    char *full_cmd;
    full_cmd = _handlepath(av[1]);
    if(full_cmd)
    printf("%s\n", full_cmd);
    else
    printf("does not exist\n");
}

*/


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
		perror("Error reading input");
		return (NULL);
	}

	return (line);

}
#include "shell.h"

char **_tokenizer(char *line)
{
	char **tokens = NULL;
	char *del = " ";
	char *token =NULL;
	int count = 0;
	size_t len ;
	char *tmp = NULL;
	int x = 0 ; 
	if(!line)
		return (NULL);
	
	/*New Edit for realloc*/
	tmp = strdup(line);
	token = strtok(tmp, del);
	if (token == NULL)
	{
		free(line) , line = NULL;
		free(tmp) , tmp = NULL;
		

	}
	while(token)
	{
			count++;
			token = strtok(NULL, del);
	}
	free(tmp);
	tokens = malloc(sizeof (char *) * (count + 1 ));

	if(!tokens)
	{
	free(line);
	return (NULL);
	}
	/*Handle Last Space In String*/
	 len = strlen(line);
	if (len > 0 && line[len-1] == '\n')
		line[len-1] = '\0';

	token = strtok(line, del);

	while (token)
	{
		tokens[x] = strdup(token);
		token = strtok(NULL, " ");
		x++;
	}
	free(line);
	free(token);
	tokens[x] = NULL;

	return (tokens);
}
