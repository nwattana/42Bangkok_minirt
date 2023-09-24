#include "../inc/minirt.h"

/// @brief mlx_my_putpixel is a function that put a pixel in the image.
/// @param img_data
/// @param width line length
/// @param bpp bits per pixel
/// @param color 
void	mlx_my_putpixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->width + x * (data->bpp >> 3));
	*(unsigned int*)dst = color;
}

/// @brief init mlx window and image
void    mlx_my_init(t_mlx_confix *vars)
{
    vars->mlx = mlx_init();
    vars->is_initmlx = 1;
    vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, PROGRAM_NAME);
    vars->is_initwin = 1;
    vars->img.img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, &vars->img.width, &vars->img.endian);
    fill_image_with_color(vars);
    vars->is_init_img = 1;

}

void fill_image_with_color(t_mlx_confix *vars)
{
    int win_x;
    int win_y;
    int color;

    win_y = 0;
    while (win_y < WINDOW_HEIGHT)
    {
        win_x = 0;
        while (win_x < WINDOW_WIDTH)
        {
            color = create_rgb(38, 97, 156);
            mlx_my_putpixel(&(vars->img), win_x, win_y, color);
            win_x++;
        }
        win_y++;
    }
}

/// @brief function handle close window
int    mlx_my_close(int key, t_mlx_confix *vars)
{
    (void)key;
    if (vars->is_init_img)
        mlx_destroy_image(vars->mlx, vars->img.img);
    if (vars->is_initwin)
        mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

// TODO: remove this function
int animation(void *program)
{
    t_prog *prog;
	int		win_x;
	int		win_y;
	int		color;
    int     loop;
    int     r;
    int     g;
    int     b;
    t_mlx_confix *vars;

    prog = (t_prog *)program;
    vars = &(prog->mlx_config);
    loop = 0;
    while (loop < 20000)
    {
        win_y = 0;
        while (win_y < WINDOW_HEIGHT)
        {
	        win_x = 0;
            while (win_x < WINDOW_WIDTH)
            {
                // all render logic here
                r = ((double)win_x / (double)WINDOW_WIDTH) * 255.0;
                g = ((double)win_y / (double)WINDOW_HEIGHT) * 255.0;
                b = (((double)win_y *  (double)win_x))  / ((double)WINDOW_HEIGHT * (double)WINDOW_WIDTH) * 255.0;

                color = create_rgb(255, 0, 0);
                if (win_x == win_y)
                    mlx_my_putpixel(&(prog->mlx_config.img), win_x, win_y, color);
                // mlx_my_putpixel(&(prog->mlx_config.img), WINDOW_WIDTH - win_x , WINDOW_HEIGHT - win_y, color * loop);
                win_x++;
            }
            mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
            usleep(10);
            win_y++;
        }
        loop++;
        }
}

/// @brief function handle loop
void prog_mlx_loop(t_prog *prog)
{
    t_mlx_confix *vars;

    vars = &(prog->mlx_config);
    // TODO Bug When exist
    mlx_hook(vars->win, 2, 0, mlx_my_close, vars);
    // X red
    mlx_hook(vars->win, 17, 0, mlx_my_close, vars);

    // Simple animation
    // mlx_loop_hook(vars->mlx, animation, prog);

    // SWITCH turn on/off mlx window
    mlx_loop(vars->mlx);
}