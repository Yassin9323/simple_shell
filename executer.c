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
                     exit(0); /* Handle ctrl + D */
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
