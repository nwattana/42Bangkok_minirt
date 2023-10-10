/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vlidator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:48:23 by narin             #+#    #+#             */
/*   Updated: 2023/10/11 01:28:30 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RT_VALIDATOR_H
# define RT_VALIDATOR_H

# include "minirt.h"

typedef struct s_inst_counter{
	int camera_count;
	int light_count;
	int object_count;
	int amb_light_count;
}	t_inst_counter;

typedef struct s_validator_util
{
	char	*gnl_line;
	char	**splited;
	char	*trimed;
	char	*err_message;
	int		is_error;

	int 	is_open_fd;
	int		opened_fd;

}	t_validator_util;

int		pre_read_config(char **argv, t_prog *prog);
int		check_line_no_implement(char *line, t_prog *prog);
int		feed_check_config(char **splited, t_prog *prog);
size_t	count_splited(char **splited);
int		valid_line_prefix(char *line, t_prog *prog);
void	init_inst_counter(t_inst_counter *ins);
void	check_inst_count(t_prog *prog);
int		debug_inst_counter(t_inst_counter *ins);
int		is_3d_realnum(char *str);
int		is_real(char *str);
int		ft_strcmp(char *str1, char *str2);
void	init_validator_util(t_validator_util *util);
int		valid_line_instruction(char **splited, t_prog *prog);
int		is_skip_line(char *line);

int		check_ambient_light_line(char **splited, t_prog *prog);
int		check_camera_line(char **splited, t_prog *prog);
int		check_light_line(char **splited, t_prog *prog);
int		check_plane_line(char **splited, t_prog *prog);
int		check_cylinder_line(char **splited, t_prog *prog);
int		check_sphere_line(char **splited, t_prog *prog);
void	free_set_null(char **ptr);
void	is_validate_error(t_prog *prog);
void	ecerr(char *message, t_prog *prog);
void	clean_gnl_buffer(int fd);
void	clean_validator_util(t_prog *prog);
int		is_rgb3d(t_vec3d *vec);
int		strreplace_space(char *str);
#endif