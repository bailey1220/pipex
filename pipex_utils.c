#include "pipex.h"

void    exit(char *str)
{
    perror(str);
    exit(1);
}