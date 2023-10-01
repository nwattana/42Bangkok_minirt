#include "../inc/minirt.h"

static int	keyhandler(int keycode);
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
// int    mlx_my_close(int key, t_mlx_confix *vars)
// {
//     (void)key;
//     if (vars->is_init_img)
//         mlx_destroy_image(vars->mlx, vars->img.img);
//     if (vars->is_initwin)
//         mlx_destroy_window(vars->mlx, vars->win);
//     return (0);
// }

static int	close_window(void)
{
	exit (0);
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
    // mlx_hook(vars->win, 2, 0, mlx_my_close, vars);
    // X red
    mlx_hook(vars->win, 17, 0, close_window, vars);

    mlx_hook(vars->win, 2, 1L << 0, &keyhandler, vars);

    // Simple animation
    // mlx_loop_hook(vars->mlx, animation, prog);

    // SWITCH turn on/off mlx window
    mlx_loop(vars->mlx);
}

static int	keyhandler(int keycode)
{
	if (keycode == KEY_LEFT || keycode == KEY_A)
		printf("KEY_A: %s\n", "LEFT");
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		printf("KEY_D: %s\n", "RIGHT");
	if (keycode == KEY_DOWN || keycode == KEY_S)
		printf("KEY_S: %s\n", "DOWN");
	if (keycode == KEY_UP || keycode == KEY_W)
		printf("KEY_W: %s\n", "UP");
    if (keycode == KEY_R)
		printf("KEY_R: %s\n", "R");
    if (keycode == KEY_Q)
        printf("KEY_Q: %s\n", "Q");
    if (keycode == KEY_0)
        printf("KEY_0: %s\n", "0");
    if (keycode == KEY_1)
        printf("KEY_1: %s\n", "1");
    if (keycode == KEY_2)
        printf("KEY_2: %s\n", "2");
    if (keycode == KEY_3)
        printf("KEY_3: %s\n", "3");
    if (keycode == KEY_4)
        printf("KEY_4: %s\n", "4");
    if (keycode == KEY_5)
        printf("KEY_5: %s\n", "5");
    if (keycode == KEY_6)
        printf("KEY_6: %s\n", "6");
    if (keycode == KEY_7)
        printf("KEY_7: %s\n", "7");
    if (keycode == KEY_8)
        printf("KEY_8: %s\n", "8");
    if (keycode == KEY_9)
        printf("KEY_9: %s\n", "9");
    if (keycode == KEY_MINUS)
        printf("KEY_MINUS: %s\n", "MINUS");
    if (keycode == KEY_PLUS)
        printf("KEY_PLUS: %s\n", "PLUS");
    if (keycode == KEY_CTRL)
        printf("KEY_CTRL: %s\n", "CTRL");
    if (keycode == KEY_SHIFT)
        printf("KEY_CTRL: %s\n", "SHIFT");
    if (keycode == KEY_SPACE)
        printf("KEY_SPACE: %s\n", "SPACE");
    if (keycode == KEY_ENTER)
        printf("KEY_ENTER: %s\n", "ENTER");
	if (keycode == KEY_ESC)
		printf("KEY_ESC: %s\n", "EXIT");
	return (0);
}