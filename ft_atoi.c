#include "ft_printf.h"

static int	ignorespaces(const char *str)
{
	int	a;

	a = 0;
	while (str[a] == ' ' || str[a] == '\t' || str[a] == '\n' || \
	str[a] == '\r' || str[a] == '\v' || str[a] == '\f')
		a++;
	return (a);
}

int	ft_atoi(const char *str)
{
	char	*text;
	int		a;
	int		neg;
	long	result;

	text = (char *)str;
	neg = 1;
	result = 0;
	a = ignorespaces(str);
	if (str[a] == '-')
		neg = -1;
	if (str[a] == '-' || str[a] == '+')
		a++;
	while (str[a] >= '0' && str[a] <= '9')
	{
		result = result * 10 + (str[a] - 48);
		a++;
		if (result * neg > 2147483647)
			return (-1);
		if (result * neg < -2147483648)
			return (0);
	}
	result = result * neg;
	return ((int)result);
}
