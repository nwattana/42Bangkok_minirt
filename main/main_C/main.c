#include "../inc/minirt.h"

void debug_mlx_status(t_mlx_confix *vars)
{
    printf("is_initmlx: %d\n", vars->is_initmlx);
    printf("is_initwin: %d\n", vars->is_initwin);
    printf("is_init_img: %d\n", vars->is_init_img);
}

int	main(int argc, char **argv)
{
    t_color a_bicolor = {255, 255, 255};
    t_ambient ambient = {0.2, 255, 255, 255};
    t_camera camera = {{0, 0, 0}, {0, 0, 1}, 90};
    t_light light = {{-40, 50, 0}, 0.6, 10, 0, 255};
    t_sphere sphere = {{0, 0, 20.6}, 12.6, 10, 0, 255};
    t_plane plane = {{0, 0, -10}, {0, 1.0, 0}, 0, 0, 255};
    t_cylinder cylinder = {{0, 0, 20.6}, 0, 0, 1, 12.6, 10, 0, 255};
	t_input		data;

    printf("a_bicolor: %d %d %d\n", a_bicolor.red, a_bicolor.green, a_bicolor.blue);
    printf("ambient: %f %d %d %d\n", ambient.ratio, ambient.color.red, ambient.color.green, ambient.color.blue);
    printf("camera: %f %f %f %f %f %f %d\n", camera.origin.x,camera.origin.y,camera.origin.z, camera.orientation.x, camera.orientation.y, camera.orientation.z, camera.fov);
    printf("light: %f %f %f %f %d %d %d\n", light.origin.x, light.origin.y, light.origin.z, light.ratio, light.color.red, light.color.green, light.color.blue);
    printf("sphere: %f %f %f %f %d %d %d\n", sphere.origin.x, sphere.origin.y, sphere.origin.z, sphere.diameter, sphere.color.red, sphere.color.green, sphere.color.blue);
    printf("plane: %f %f %f %f %f %f %d %d %d\n", plane.origin.x, plane.origin.y, plane.origin.z, plane.orientation.x, plane.orientation.y, plane.orientation.z, plane.color.red, plane.color.green, plane.color.blue);
    printf("cylinder: %f %f %f %f %f %f %f %f %d %d %d\n", cylinder.origin.x, cylinder.origin.y, cylinder.origin.z, cylinder.orientation.x, cylinder.orientation.y, cylinder.orientation.z, cylinder.diameter, cylinder.height, cylinder.color.red, cylinder.color.green, cylinder.color.blue);

    // if (argc != 2)
	// 	error_file("Error\n");
	// if (argc == 2)
	// {
	// 	read_input(&data, argv[1]);
	// }


    // t_mlx_confix vars;

    // mlx_my_init(&vars);


    
    // mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
    // mlx_my_loop(&vars);





















    return (0);
}
