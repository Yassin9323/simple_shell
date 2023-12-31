#include "shell.h"

int _executer(char **tokens, char **argv, int x)
{
    pid_t test;
    int status ;
    char *full_command;

    full_command = _getpath(tokens[0]);
    if(!full_command)
    {
        dis_errors(argv[0], tokens[0], x);
        freearray2D(tokens);
        return(127);
    }

    test = fork();

    if(test == 0 ) /* test process */
    {
           if (execve(full_command, tokens, environ) == -1 )
            {
                free(full_command), full_command = NULL;
                freearray2D(tokens);
            }
    }
    else
    {
        waitpid(test, &status, 0);
        freearray2D(tokens);
        free(full_command), full_command = NULL;
    }

    return (WEXITSTATUS(status));
}
