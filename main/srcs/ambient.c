#include "../inc/minirt.h"

void    print_ambient(void *amb)
{
    t_ambient *ambient;

    ambient = (t_ambient *)amb;
    printf(H_LINE);
    printf("Ambient:\n");
    printf("  intensity: %f\n", ambient->intensity);
    printf("  color: %d, %d, %d\n", ambient->color.r, ambient->color.g, ambient->color.b);
    printf(H_LINE);
}

void    clean_ambient(void *amb)
{
    t_ambient *ambient;

    ambient = (t_ambient *)amb;
    return ;
}