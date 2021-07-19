#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_brain	brainwash(t_brain brain)
{
	brain.ctype = '-';
	brain.bzero = 0;
	brain.bneg = 0;
	brain.bdot = 0;
	brain.bplus = 0;
	brain.bspace = 0;
	brain.bhash = 0;
	brain.imnchr = 0;
	brain.imnchrzro = 0;
	brain.imxchr = 0;
	brain.imxchrzro = 0;
	return (brain);
}

t_brain	printez(t_brain brain)
{
	while (brain.strin[brain.loc] && brain.strin[brain.loc] != '%')
	{
		write(1, &brain.strin[brain.loc], 1);
		brain.totalen++;
		brain.loc++;
	}
	if (!brain.strin[brain.loc])
	{
		brain.bemergencybreak = 1;
	}
	return (brain);
}

int	ft_printf(const char *masstr, ...)
{
	t_brain	brain;
	va_list	arguments;

	brain.strin = ft_strdup(masstr);
	brain.bemergencybreak = 0;
	brain.totalen = 0;
	brain.loc = 0;
	va_start(arguments, masstr);
	brain.args = &arguments;
	while (!brain.bemergencybreak)
	{
		brain = brainwash(brain);
		brain = printez(brain);
		if (!brain.bemergencybreak)
			brain = paramdetector(brain);
	}
	free(brain.strin);
	va_end(arguments);
	return (brain.totalen);
}
