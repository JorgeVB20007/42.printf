#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

char	*addazero(char *str)
{
	char	*newstr;
	int		a;
	int		b;

	newstr = malloc(ft_strlen(str) + 2);
	b = ft_strlen(str);
	a = 0;
	newstr[0] = '0';
	while (a < b)
	{
		newstr[a + 1] = str[a];
		a++;
	}
	newstr[a + 1] = 0;
	free(str);
	return (newstr);
}

static t_brain	writing_the_num(t_brain brain, char *string)
{
	int	dif;

	dif = 0;
	while (string[dif])
	{
		if (string[dif] != '-' && string[dif] != '+' && string[dif] != ' ')
			write(1, &string[dif], 1);
		brain.totalen++;
		dif++;
	}
	return (brain);
}

t_brain	int_string_printer(t_brain brain, char *string)
{
	int		dif;

	if (string[0] == '-' || string[0] == '+' || string[0] == ' ' )
		write(1, &string[0], 1);
	if (ft_strlen(string) < brain.imnchr && !brain.bneg)
	{
		dif = brain.imnchr;
		while (dif-- - ft_strlen(string))
			brain = spaceandcount(brain);
	}
	brain = writing_the_num(brain, string);
	if (ft_strlen(string) < brain.imnchr && brain.bneg)
	{
		dif = brain.imnchr;
		while (dif-- - ft_strlen(string))
			brain = spaceandcount(brain);
	}
	free(string);
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
	while (ft_strlen(thestr) < brain.imxchr)
		thestr = addazero(thestr);
	if (thenum < 0 || brain.bspace || brain.bplus)
	{
		thestr = addazero(thestr);
		if (thenum < 0)
			thestr[0] = '-';
		else if (brain.bspace)
			thestr[0] = ' ';
		else
			thestr[0] = '+';
	}
	brain = int_string_printer(brain, thestr);
	return (brain);
}
