#include "shell.h"
void dis_errors(char *name, char *cmd, int x )
{
    char *index;
    char mssg[] = ": not found\n";
    index = int_to_asci(x);

    write(STDERR_FILENO, name, strlen(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, strlen(index));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, strlen(cmd));
    write(STDERR_FILENO, mssg, strlen(mssg));

    free(index);

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
