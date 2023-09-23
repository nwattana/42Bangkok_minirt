#include "libft.h"

/// @return `1` on error, `0` on success
int ft_free_split(char **split_obj)
{
    int i;

    i = 0;
    if (!split_obj)
        return (1);
    while (split_obj[i])
    {
        free(split_obj[i]);
        i++;
    }
    free(split_obj);
    return (0);
}