#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_s(void)
{
	t_brain	brain;
	int		dif;
	char	*string;
	va_list	arguments;

	write(1, "It's a string!", 13);
	string = va_arg (arguments, char *);
	if (ft_strlen(string) < brain.iminchar && !brain.bneg)
	{
		dif = brain.iminchar;
		while (dif-- - ft_strlen(string))
			write(1, " ", 1);
	}
	if ((ft_strlen(string) > brain.imaxchar || brain.imaxcharzero) && !brain.bneg)
	{
		dif = brain.imaxchar;
		while (ft_strlen(string) - dif++)
			write(1, " ", 1);
		write(1, &string, brain.imaxchar);
	}
	if ((ft_strlen(string) > brain.imaxchar || brain.imaxcharzero) && brain.bneg)
	{
		write(1, &string, brain.imaxchar);
		dif = brain.imaxchar;
		while (ft_strlen(string) - dif++)
			write(1, " ", 1);
	}
	if (ft_strlen(string) < brain.iminchar && !brain.bneg)
	{
		dif = brain.iminchar;
		while (dif-- - ft_strlen(string))
			write(1, " ", 1);
	}
	dif = 0;
	if (ft_strlen(string) < brain.imaxchar && ft_strlen(string) > brain.iminchar)
	{
		while (string[dif])
		{
			write(1, &string[dif], 1);
			dif++;
		}
	}
}