#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/***********************
*                       *
*     THE GOOD ONE      *
*                       *
 ***********************/


t_brain	typesorter(t_brain brain)
{
	if (brain.ctype == 's')
		brain = ft_s(brain);
	if (brain.ctype == 'c')
		brain = ft_c(brain);
/*	if (brain.ctype == 'd' || brain.ctype == 'i')
		ft_id(void);
	if (brain.ctype == 'u')
		ft_u(void);
	if (brain.ctype == 'x' || brain.ctype == 'X')
		ft_x(void);
	if (brain.ctype == '%')
		ft_percent(void);*/
		return (brain);
}

t_brain	paramdetector(t_brain brain)
{
	int		completed;

	completed = 0;
	while (!completed)
	{
		if (ft_isalpha(brain.strin[brain.loc]))
		{
			completed++;
			brain.ctype = brain.strin[brain.loc];
		}
		else if (brain.strin[brain.loc] == '-')
			brain.bneg = 1;
		else if (brain.strin[brain.loc] == '0' && !brain.bperiod && !brain.iminchar)
			brain.bzero = 1;
		else if (brain.strin[brain.loc] == '.')
			brain.bperiod = 1;
		else if (brain.strin[brain.loc] == '+')
			brain.bplus = 1;
		else if (brain.strin[brain.loc] == ' ')
			brain.bspace = 1;
		else if (brain.strin[brain.loc] == '#')
			brain.bhash = 1;
		else if (ft_isdigit(brain.strin[brain.loc]) && !brain.bperiod)
			brain.iminchar = brain.iminchar * 10 + (brain.strin[brain.loc] - 48);
		else if (ft_isdigit(brain.strin[brain.loc]) && brain.bperiod)
			brain.imaxchar = brain.imaxchar * 10 + (brain.strin[brain.loc] - 48);
		brain.loc++;
	}
//	printbrain(brain);
	brain = typesorter(brain);
	return (brain);
}
