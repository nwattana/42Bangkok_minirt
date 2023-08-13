#include <stdio.h>
#include "../mlx/mlx.h"

// TEST init mlx
int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 600, 480, "Hello world!");
    mlx_loop(mlx);
    return (0);
}