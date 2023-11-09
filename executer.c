#include "shell.h"

int _executer(char **tokens, char **argv)
{
    pid_t test;
    int status ;

    test = fork();

    if(test == 0 ) /* Child process */
    {
           if (execve(tokens[0], tokens, environ) == -1 )
            {
                     perror(argv[0]);
                     _free_memory(tokens);
                     exit(0); /* Handle ctrl + D */
            }
    }
    else 
    {
        waitpid(test, &status, 0);
        _free_memory(tokens);
    }

    return (WEXITSTATUS(status));
}
