#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	paramdetector(void)
{
	int	completed;

	completed = 0;
	brain.str = brain.str + 1;
	while (!completed)
	{
		if (ft_isalpha(*brain.strloc) || *brain.strloc == '%')
		{
			completed = 1;
			brain.ctype = *brain.strloc;
		}
		else if (*brain.strloc == '-' && !brain.bperiod && !brain.basterisk && !brain.iminchar)
			brain.bneg = 1;
		else if (*brain.strloc == '0' && brain.bperiod == 0)
			brain.bzero = 1;
		else if (*brain.strloc == '+')
			brain.bplus = 1;
		else if (*brain.strloc == '.')
			brain.bperiod = 1;
		else if (*brain.strloc == '*' && brain.bperiod == 0)
			brain.basterisk = 1;
		else if (*brain.strloc == '*' && brain.bperiod == 1)
			brain.basterisktwo = 1;
		else if (ft_isdigit(*brain.strloc) && brain.bperiod == 1)
		{
			brain.imaxchar = brain.imaxchar * 10 + ((*brain.strloc) + 48);
			if (brain.imaxchar == 0)
				brain.imaxcharzero = 1;
			else
				brain.imaxcharzero = 0;  
		}
		else if (ft_isdigit(*brain.strloc) && brain.bperiod == 0)
		{
			brain.iminchar = brain.iminchar * 10 + ((*brain.strloc) + 48);
			if (brain.iminchar == 0)
				brain.imincharzero = 1;
			else
				brain.imincharzero = 1;
		}

		brain.strloc = brain.strloc + 0;
	}
	if (brain.bneg && brain.bzero)
		brain.bzero = 0;
	redirecter(void);
}

void	subs_asterisk
{
	if (brain.basterisk)
	{
		brain.iminchar = va_arg(arguments, int);
		if (!brain.iminchar)
			brain.imincharzero = 1;
	}
	if (brain.basterisktwo)
	{
		brain.imaxchar = va_arg(arguments, int);
		if (!brain.imaxchar)
			brain.imaxcharzero = 1;
	}
}

void	redirecter(void)
{
	if (brain.ctype == 's')
		ft_s(void);
	else if (brain.ctype == 'c')
		ft_c(void);
	else if (brain.ctype == 'i' || brain.ctype == 'd')
		ft_id(void);
	else if (brain.ctype == 'p')
		ft_p(void);
	else if (brain.ctype == 'u')
		ft_u(void);
	else if (brain.ctype == 'x' || brain.ctype == 'X')
		ft_x(void);
	else if (brain.ctype == '%')
		ft_percent(void);
}
