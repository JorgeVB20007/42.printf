#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/***********************
*                       *
*     THE GOOD ONE      *
*                       *
 ***********************/


void	typesorter(void)
{
	t_brain	brain;

	if (brain.ctype == 's')
		ft_s();
/*	if (brain.ctype == 'c')
		ft_c(void);
	if (brain.ctype == 'd' || brain.ctype == 'i')
		ft_id(void);
	if (brain.ctype == 'u')
		ft_u(void);
	if (brain.ctype == 'x' || brain.ctype == 'X')
		ft_x(void);
	if (brain.ctype == '%')
		ft_percent(void);*/
}

void	paramdetector(void)
{
	t_brain	brain;
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
		else if (brain.strin[brain.loc] == '0')
			brain.bzero = 1;
		else if (brain.strin[brain.loc] == '*' && !brain.bperiod && !brain.iminchar)
			brain.basterisk = 1;
		else if (brain.strin[brain.loc] == '.')
			brain.bperiod = 1;
		else if (ft_isdigit(brain.strin[brain.loc]) && !brain.bperiod)
			brain.iminchar = brain.iminchar * 10 + brain.strin[brain.loc] + 48;
		else if (ft_isdigit(brain.strin[brain.loc]) && brain.bperiod)
			brain.imaxchar = brain.imaxchar * 10 + brain.strin[brain.loc] + 48;
	}
}
