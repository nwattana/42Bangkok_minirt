#include "../../inc/minirt.h"

/// @brief program with printing error message
void error_exit(char *msg, t_prog *prog)
{
	printf("%s", msg);
	exit(prog->p_state);
}

/// @brief basic validate args
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
	// prog->p_state = PASS_VALIDATE_ARGS;
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
		debug_message(line);
		free(line);
	}
	close(fd);
	return (0);
}

/// @brief Check starting charactor
/// @return 1 if valid, 0 if invalid
int read_2bytes(char *line)
{
	if (line == NULL)
		return (0);
	if (ft_strchr("C#ALspc", line[0]) || ft_strncmp(&line[0], "//", 3))
		return (1);
	return (0);
}

static int	ft_isvalue(char *str)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (str[0] == '-')
		i++;
	else if (str[0] == ',')
		return (0);
	
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (point >= 2 && !ft_isdigit(str[i - 1]))
				return (0);
			if (str[i] == '.' )
			{
				if (!ft_isdigit(str[i - 1]) || !ft_isdigit(str[i + 1]))
					return (0);
				else
					point++;
				i++;
			}
			else if (str[i] == ',' || str[i] == '-')
				i++;
			else
				return (0);
		}
		else
			i++;
	}
	return (1);
}

static int count_idx(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

static int check_line_value(char **str, int idx, t_prog *prog)
{	
	int len;
	int i;

	len = count_idx(str);
	i = 1;
	if (len > idx)
		error_exit("Error\n wrong value\n", prog);
	if (ft_strncmp(str[0], "//", ft_strlen(str[0])) == 0)
		return (0);
	while (str[i] && i < idx)
	{
		if (!(ft_isvalue(str[i])))
			error_exit("Error\n wrong value\n", prog);
		i++;
	}
	return (0);
}

int check_line_type(char **splited_lint, t_prog *prog)
{
	if (ft_strncmp(splited_lint[0], "C", ft_strlen(splited_lint[0])) == 0)
	{
		collect_camera(splited_lint, prog);
	}
	if (ft_strncmp(splited_lint[0], "A", ft_strlen(splited_lint[0])) == 0)
	{
		collect_ambient(splited_lint, prog);
	}
	if (ft_strncmp(splited_lint[0], "L", ft_strlen(splited_lint[0])) == 0)
	{
		collect_light(splited_lint, prog);
	}
	if (ft_strncmp(splited_lint[0], "sp", ft_strlen(splited_lint[0])) == 0)
	{
		collect_sphere(splited_lint, prog);
	}
	if (ft_strncmp(splited_lint[0], "pl", ft_strlen(splited_lint[0])) == 0)
	{
		collect_plane(splited_lint, prog);
	}
	return (0);
}

static int	get_index(char **str)
{
	int	index;

	if (ft_strncmp(str[0], "A", ft_strlen(str[0])) == 0)
		index = 3;
	else if (ft_strncmp(str[0], "cy", ft_strlen(str[0])) == 0)
		index = 6;
	else if (ft_strncmp(str[0], "//", ft_strlen(str[0])) == 0)
		index = count_idx(str);
	else 
		index = 4;
	return (index);
}

int check_line(char *lint, t_prog *prog)
{
	char **split_out;
	char *line;
	int		index;

	line = ft_strtrim(lint, " \t\n");
	if (!read_2bytes(line))
	{
		// FIXME: error message grouping
		prog->p_error = 1;
	}
	else
	{
		split_out = ft_split(line, ' ');
		index = get_index(split_out);
		check_line_value(split_out, index, prog);
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