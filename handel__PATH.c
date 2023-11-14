#include "shell.h"

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
