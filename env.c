#include "shell.h"

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
