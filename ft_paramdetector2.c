#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_error(int a, char *errmess)
{
	int	b;

	b = 0;
	write(1, "ERROR: ", 7);
	while (errmess[b])
	{
		write(1, &errmess[b], 1);
		b++;
	}
	b = 0;
	write(1, "\n>> printf(\"", 12);
	while (brain.strin[b])
	{
		write(1, &brain.strin[b], 1);
		b++;
	}
	write(1, "\" ...\n           ", 16);
	b = 0;
	while (a < b - 1)
		write(1, " ", 1);
	write(1)
}

void	typesorter(void)
{
	if (brain.ctype == 's')
		ft_s(void);
	if (brain.ctype == 'c')
		ft_s(void);
	if (brain.ctype == 'd' || brain.ctype == 'i')
		ft_s(void);
	if (brain.ctype == 'u')
		ft_s(void);
	if (brain.ctype == 'x')
		ft_s(void);
}

void	paramdetector(void)
{
	t_brain	brain;
	int	completed;

	completed = 0;
	while (!completed)
	{
		if (ft_isalpha(brain.strin[brain.loc]))
		{
			completed++;
			brain.ctype = brain.strin[brain.loc];
		}
		else if (brain.strin[brain.loc] == '-' && !brain.bperiod && !brain.iminchar && !brain.basterisk)
			brain.bneg = 1;
		else if (brain.strin[brain.loc] == '-')
			ft_error(loc, "'-' cannot be placed here.");
		else if (brain.strin[brain.loc] == '0' && !brain.bperiod && !brain.iminchar && !brain.basterisk)
			brain.bzero = 1;
		else if (brain.strin[brain.loc] == '0' && (brain.basterisk && !brain.bperiod || brain.basterisktwo))
			ft_error(loc, "'0' cannot be placed here.");
		else if (brain.strin[brain.loc] == '0' && brain.bperiod)
		{
			if (!brain.imaxchar)
				brain.imaxcharzero = 1;
			else
				brain.imaxchar = brain.imaxchar * 10;
		}
		else if (brain.strin[brain.loc] == '0')
		{
			if (!brain.iminchar)
				brain.imincharzero = 1;
			else
				brain.iminchar = brain.iminchar * 10;
		}
		else if (brain.strin[brain.loc] == '*' && !brain.bperiod && !brain.iminchar)
			brain.basterisk = 1;
		else if (brain.strin[brain.loc] == '*' && brain.bperiod && !brain.imaxchar)
			brain.basterisktwo = 1;
		else if (brain.strin[brain.loc] == '*' && brain.basterisk && brain.basterisktwo)
			ft_error(brain.loc, "'*' has been used more than twice.");
		else if (brain.strin[brain.loc] == '*')
			ft_error(brain.loc, "'*' cannot be placed here.");
		else if (brain.strin[brain.loc] == '.' && brain.bperiod)
			ft_error(brain.loc, "Duplicated '.'");
		else if (brain.strin[brain.loc] == '.')
			brain.bperiod = 1;
		else if (ft_isdigit(brain.strin[brain.loc]) && !brain.bperiod)
			brain.iminchar = brain.iminchar * 10 + brain.strin[brain.loc] + 48;
		else if (ft_isdigit(brain.strin[brain.loc]) && brain.bperiod)
			brain.imaxchar = brain.imaxchar * 10 + brain.strin[brain.loc] + 48;
	}
}
