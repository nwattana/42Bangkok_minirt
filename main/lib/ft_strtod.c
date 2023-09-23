#include "libft.h"

/// @brief check if the string is a valid double
/// @param str is the string to check
int str_tocheck(char *str, int *sign, int *is_fraction)
{
	int     i;
	char    prv;

	prv = '\0';
	i=0;
	while (str[i])
	{
		if (!ft_strchr("0123456789.+-", str[i]))
			return (1);
		if (str[i] == '+' || str[i] == '-')
			*sign += 1;
		if (str[i] == '.')
			*is_fraction += 1;
		prv = str[i];
		i++;
	}
	if (prv == '+' || prv == '-' || \
	prv == '.' || *sign > 1 || *is_fraction > 1)
		return (1);
	return (0);
}

int    ft_atod(char *str, double *destination)
{
	double  result;
	int     ret;

	ret = 0;
	result = 0.0;
	while (str[ret] != '.'&& str[ret])
	{
		result = result * 10 + (str[ret] - '0');
		ret++;
	}
	*destination = result;
	return (ret);
}

int ft_atod_fraction(char *str, double *destination)
{
	double  fraction;
	int     ret;
	double  result;

	ret = 0;
	fraction = 0.1;
	result = 0.0;
	if (str[ret] == '.')
		ret++;
	while (str[ret] != '\0')
	{
		result = result + (str[ret] - '0') * fraction;
		fraction *= 0.1;
		ret++;
	}
	*destination += result;
	return (ret);
}

/// @brief convert a string to a double
/// @param str is the string to convert
/// @param destination is the pointer to the double to convert
/// @return error code
int  ft_strtod(char *str, double *destination)
{
	double  result;
	int     sign;
	int     is_fraction;


	if (!str || !destination)
		return (-1);
	is_fraction = 0;
	sign = 0;
	result = 0.0;
	if (str_tocheck(str, &sign, &is_fraction))
		return (-1);
	str = str + ft_atod(str + sign, &result);
	if (is_fraction)
		str += ft_atod_fraction(str + is_fraction, &result) + is_fraction;
	*destination = result;
	if (sign)
		*destination *= -1;
	return (0);
}
// TODO NORMINETTE