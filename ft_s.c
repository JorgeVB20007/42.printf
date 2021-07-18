#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_brain	spaceandcount(t_brain brain)
{
	if (brain.ctype == 'd' || brain.ctype == 'i' || brain.ctype == 'u')
	{
		if (brain.bzero && !brain.bperiod)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	else if (brain.ctype == 'x' || brain.ctype == 'X' || brain.ctype == '%')
	{
		if (brain.bzero && !brain.bperiod)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	else
		write(1, " ", 1);
	brain.totalen++;
	return (brain);
}

char	*stringtrimmer(t_brain brain, char *inistring)
{
	char	*newstring;
	int		a;

	a = 0;
	if (!inistring)
		inistring = ft_strdup("(null)");
	if (brain.bperiod && !brain.imaxchar && !brain.imaxcharzero)
		return (ft_strdup(""));
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
		return (ft_strdup(inistring));
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
	free (string);
	return (brain);
}