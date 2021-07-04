#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_strlen(char *s)
{
	int	n;

	n = 0;
	while ((*(s + n)) != '\0')
		n++;
	return (n);
}

int	ft_intlen(int a)
{
	int	n;

	n = 0;
	if (a == -2147483648)
		return (11);
	if (a < 0)
	{
		n = 1;
		a = a * -1;
	}
	while (a > 0)
	{
		a = a / 10;
		n++;
	}
	return (n);
}

void	spacer(int a)
{
	while (a > 0)
	{
		write(1, " ", 1);
		a--;
	}
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
