#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_brain	ft_s(t_brain brain)
{
	int		dif;
	char	*string = NULL;

//	write(1, "It's a string!", 14);
	string = va_arg (*brain.args, char *);
	if (ft_strlen(string) < brain.iminchar && !brain.bneg)
	{
		dif = brain.iminchar;
		while (dif-- - ft_strlen(string))
			write(1, " ", 1);
	}
	if (((ft_strlen(string) > brain.imaxchar && brain.imaxchar) || brain.imaxcharzero) && !brain.bneg)
	{
		dif = brain.imaxchar;
		while (ft_strlen(string) - dif++)
			write(1, " ", 1);
		write(1, &string, brain.imaxchar);
	}
	if (ft_strlen(string) > brain.imaxchar || ft_strlen(string) < brain.iminchar)
	{
		dif = 0;
		while (string[dif])
		{
			write(1, &string[dif], 1);
			dif++;
		}
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
	return (brain);
}