#include "../../inc/minirt.h"

/// @brief Only collect color from string please check if the string is valid
int     collect_color(char *color_string, t_color *color)
{
    char    **split_color;

    split_color = ft_split(color_string, ',');
    if (split_color == NULL)
        return (1);
    color->r = ft_atoi(split_color[0]);
    color->g = ft_atoi(split_color[1]);
    color->b = ft_atoi(split_color[2]);
    ft_free_split(split_color);
    return (0);
}

int     assign_color(t_color *color, int r, int g, int b)
{
    color->r = r;
    color->g = g;
    color->b = b;
    return (0);
}

int     s_get_rgb(t_color *color)
{
    return (create_rgb(color->r, color->g, color->b));
}

// FIXME: Validation
// // FIXME: move file
// int     validate_color_string(char *color_string)
// {
//     char    **split_color;

//     if (count_char(color_string, ',') != 2)
//         return (1);
//     split_color = ft_split(color_string, ',');
//     if (split_color == NULL)
//         return (1);
//     if (ft_strslen(split_color) != 3)
//         return (1);
//     if (!ft_isdigit_str(split_color[0]))
//         return (1);
//     if (!ft_isdigit_str(split_color[1]))
//         return (1);
//     if (!ft_isdigit_str(split_color[2]))
//         return (1);
//     ft_free_split(split_color);
//     return (0);
// }

// // FIXME: move file
// int ft_isdigit_str(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         if (!ft_isdigit(str[i]))
//             return (0);
//         i++;
//     }
//     return (1);
// }

// // TODO: Check for - and . more than one time
// int ft_isdecimal_str(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         if (!ft_strchr("0123456789.", str[i]))
//             return (0);
//         i++;
//     }
// }