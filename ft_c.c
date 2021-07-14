#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_brain	ft_c(t_brain brain)
{
	int		dif;
	char	cara;

//	write(1, "It's a char!", 12);
	cara = va_arg (*brain.args, int);
	dif = 0;
	while (dif + 1 < brain.iminchar && !brain.bneg)
	{
		write(1, " ", 1);
		brain.totalen++;
		dif++;
	}
	write(1, &cara, 1);
	brain.totalen++;
	while (dif + 1 < brain.iminchar && brain.bneg)
	{
		write(1, " ", 1);
		brain.totalen++;
		dif++;
	}
	return (brain);
}
