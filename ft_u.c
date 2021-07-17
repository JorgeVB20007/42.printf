#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_brain	ft_u(t_brain brain)
{
	unsigned int	thenum;
	unsigned int	thenewnum;
	char			*thestr;

	thenum = va_arg (*brain.args, unsigned int);
	thenewnum = thenum;
	thestr = ft_itoa(thenewnum);
	while (ft_strlen(thestr) < brain.imaxchar)
		thestr = addazero(thestr);
	brain = int_string_printer(brain, thestr);
	return (brain);
}


t_brain	ft_percent(t_brain brain)
{
	char		*thestr;

	thestr = malloc(2);
	thestr[0] = '%';
	thestr[1] = 0;
	brain = int_string_printer(brain, thestr);
	return (brain);
}