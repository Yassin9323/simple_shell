#include "shell.h"

void _printf(char *string, int descriptor)
{
        int i = 0;

        for (; string[i] != '\0'; i++)
                write(descriptor, &string[i], 1);
}
