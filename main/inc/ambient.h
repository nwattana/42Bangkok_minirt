#ifndef AMBIENT_H
# define AMBIENT_H

# include "minirt.h"

typedef struct s_ambient
{
    int     count;
    double      intensity;
    t_color     color;
}           t_ambient;

void       print_ambient(void *ambient);
void       clean_ambient(void *ambient);


#endif