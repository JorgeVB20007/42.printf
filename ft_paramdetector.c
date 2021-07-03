#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	paramdetector(void)
{
	int	completed;

	completed = 0;
	brain.strloc = brain.strloc + 1;
	while(!completed)
	{
		if (ft_isalpha(*brain.strloc) || *brain.strloc == '%')
		{
			completed = 1;
			brain.ctype = *brain.strloc;
		}
		else if (*brain.strloc == '+')
			brain.bplus = 1;
		else if (*brain.strloc == '-')
			brain.bneg = 1;
		else if (*brain.strloc == '0')
			brain.bzero = 1;
		else if (*brain.strloc == '.')
			brain.bperiod = 1;
		else if (*brain.strloc == '*')
			brain.basterisk = 1;
		else if (*brain.strloc == '%')
		{
			write(1, "%%", 1);
		}
	}
	if (brain.bneg && brain.bzero)
		brain.bzero = 0;
	redirecter(void);
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
		write(1, "%%", 1);
}
