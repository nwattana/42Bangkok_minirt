#include "libft.h"

size_t  ft_strslen(char **strs)
{
    size_t  i;

    i = 0;
    if (strs == NULL)
        return (0);
    while (strs[i])
        i++;
    return (i);
}