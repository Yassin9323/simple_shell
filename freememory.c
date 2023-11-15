#include "shell.h"

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
