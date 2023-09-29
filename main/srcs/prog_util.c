#include "../inc/minirt.h"

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
	prog->p_state = PASS_VALIDATE_ARGS;
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

    return (0);
}

int	read_rt_file(char *filepath, t_prog *prog)
{
	int		fd;
	char	*line;

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
	prog->p_state = PASS_READ_RT_FILE;
	return (0);
}

/// @brief Check starting charactor
/// @return 1 if valid, 0 if invalid
int read_2bytes(char *line)
{
	int i;

	if (line == NULL)
		return (0);
	if (ft_strchr("C#ALs", line[0]))
		return (1);
	return (0);
}

int check_line_type(char **splited_lint, t_prog *prog)
{
	char	*item;

	item = splited_lint[0];
	if (ft_strncmp(item, "C", ft_strlen(item)) == 0)
	{
		collect_camera(splited_lint, prog);
	}
	if (ft_strncmp(item, "A", ft_strlen(item)) == 0)
	{
		collect_ambient(splited_lint, prog);
	}
	if (ft_strncmp(item, "L", ft_strlen(item)) == 0)
	{
		collect_light(splited_lint, prog);
	}
	if (ft_strncmp(item, "sp", ft_strlen(item)) == 0)
	{
		collect_sphere(splited_lint, prog);
	}
}

int check_line(char *lint, t_prog *prog)
{
	char **split_out;
	char *line;

	line = ft_strtrim(lint, " \t\n");
	if (!read_2bytes(line))
	{
		// FIXME: error message grouping
		printf("Error\nWrong file format\n");
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
	printf(RED"DEBUG:"CLOSE);
	printf(" %s\n", msg);
}