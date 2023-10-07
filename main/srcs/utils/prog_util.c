#include "../../inc/minirt.h"

void error_exit(char *msg, t_prog *prog)
{
	printf("%s", msg);
	exit(prog->p_state);
}

int validate_args(int argc, char **argv, t_prog *prog)
{
	int i;
	size_t len;

	i = 0;
	if (argc < 2)
		error_exit("Error\nNo arguments\n", prog);
	if (argc != 2)
		error_exit("Error\nToo many arguments\n", prog);
	len = ft_strlen(argv[1]);
	if (len < 4)
		error_exit("Error\nWrong file extension\n", prog);
	if (ft_strncmp(argv[1] + len - 3, ".rt", 3) != 0)
		error_exit("Error\nWrong file extension\n", prog);
	return (0);
}

int prog_constructor(t_prog *prog)
{
    prog->p_state = 1;
    prog->p_error = 0;
	prog->obj = NULL;
	prog->has_camera = 0;
	prog->has_ambient = 0;
	prog->has_light = 0;
	prog->item_count = 0;
    return (0);
}

int	read_rt_file(char *filepath, t_prog *prog)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		error_exit("Error\n file not found", prog);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_line(line, prog);
		free(line);
	}
	close(fd);
	return (0);
}

int read_2bytes(char *line)
{
	if (line == NULL)
		return (0);
	if (ft_strchr("C#ALspc", line[0]))
		return (1);
	return (0);
}

int check_line_type(char **spl, t_prog *prog)
{
	if (ft_strncmp(spl[0], "C", ft_strlen(spl[0])) == 0)
		collect_camera(spl, prog);
	if (ft_strncmp(spl[0], "A", ft_strlen(spl[0])) == 0)
		collect_ambient(spl, prog);
	if (ft_strncmp(spl[0], "L", ft_strlen(spl[0])) == 0)
		collect_light(spl, prog);
	if (ft_strncmp(spl[0], "sp", ft_strlen(spl[0])) == 0)
		collect_sphere(spl, prog);
	if (ft_strncmp(spl[0], "pl", ft_strlen(spl[0])) == 0)
		collect_plane(spl, prog);
	if (ft_strncmp(spl[0], "cy", ft_strlen(spl[0])) == 0)
		collect_cylinder(spl, prog);
	return (0);
}

int check_line(char *lint, t_prog *prog)
{
	char **split_out;
	char *line;

	line = ft_strtrim(lint, " \t\n");
	if (!read_2bytes(line))
	{
		prog->p_error = 1;
	}
	else
	{
		split_out = ft_split(line, ' ');
		check_line_type(split_out, prog);
		ft_free_split(split_out);
	}
	free(line);
	return (0);
}

int		count_char(char *str, int c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
		{
			counter++;
		}
		i++;
	}
	return (counter);
}

void  debug_message(char *msg)
{
	ft_putstr_fd(RED"DEBUG:"CLOSE, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}