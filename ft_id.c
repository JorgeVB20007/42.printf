#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

char	*addazero(char *str)
{
	char	*newstr;
	int		a;

	newstr = malloc(ft_strlen(str) + 2);
	a = 0;
	newstr[0] = '0';
	while (str[a])
	{
		newstr[a + 1] = str[a];
		a++;
	}
	newstr[a + 1] = 0;
	free(str);
	return (newstr);
}

t_brain	int_string_printer(t_brain brain, char *string)
{
	int		dif;

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

t_brain	ft_id(t_brain brain)
{
	double		thenum;
	double		thenewnum;
	char		*thestr;

	thenum = (double)va_arg (*brain.args, int);
	thenewnum = thenum;
	if (thenewnum < 0)
		thenewnum = thenewnum * -1;
	thestr = ft_itoa(thenewnum);
	while (ft_strlen(thestr) < brain.imaxchar)
		thestr = addazero(thestr);
	if (thenum < 0)
	{
		thestr = addazero(thestr);
		thestr[0] = '-';
	}
	else if (brain.bspace || brain.bplus)
	{
		thestr = addazero(thestr);
		if (brain.bspace)
			thestr[0] = ' ';
		else
			thestr[0] = '+';
	}
	brain = int_string_printer(brain, thestr);
	return (brain);
}
