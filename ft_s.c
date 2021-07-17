#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_brain	spaceandcount(t_brain brain)
{
	write(1, " ", 1);
	brain.totalen++;
	return (brain);
}

char	*stringtrimmer(t_brain brain, char *inistring)
{
	char	*newstring;
	int		a;

	a = 0;
	if ((ft_strlen(inistring) > brain.imaxchar && brain.imaxchar) || brain.imaxcharzero)
	{
		newstring = malloc (brain.imaxchar + 1);
		while (a < brain.imaxchar)
		{
			newstring[a] = inistring[a];
			a++;
		}
		newstring[a] = 0;
		return (newstring);
	}
	else
		return (inistring);
}

t_brain	ft_s(t_brain brain)
{
	int		dif;
	char	*string = NULL;

	string = stringtrimmer(brain, va_arg (*brain.args, char *));
	if (ft_strlen(string) < brain.iminchar && !brain.bneg)
	{
		dif = brain.iminchar;
		while (dif-- - ft_strlen(string))
			brain = spaceandcount(brain);
	}
	dif = 0;
	while (string[dif])
	{
		write(1, &string[dif], 1);
		brain.totalen++;
		dif++;
	}
	if (ft_strlen(string) < brain.iminchar && brain.bneg)
	{
		dif = brain.iminchar;
		while (dif-- - ft_strlen(string))
			brain = spaceandcount(brain);
	}
	return (brain);
}