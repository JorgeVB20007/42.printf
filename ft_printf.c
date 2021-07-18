#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	printbrain(t_brain brain)
{
	int h;
	write(1, "\nctype: '", 9);
	write(1, &brain.ctype, 1);
	write(1, "'\nbzero: ", 9);
	h = brain.bzero + 48;
	write(1, &h, 1);
	write(1, "\nbneg: ", 7);
	h = brain.bneg + 48;
	write(1, &h, 1);
	write(1, "\nbperiod: ", 10);
	h = brain.bperiod+48;
	write(1, &h, 1);
	write(1, "\nbplus: ", 8);
	h = brain.bplus+48;
	write(1, &h, 1);
	write(1, "\nbspace: ", 9);
	h = brain.bspace+48;
	write(1, &h, 1);
	write(1, "\nbhash: ", 8);
	h = brain.bhash+48;
	write(1, &h, 1);
	write(1, "\niminchar: ", 11);
	h = brain.iminchar;
	printf("%d\n", h);
	write(1, "imincharzero: ", 14);
	h = brain.imincharzero+48;
	write(1, &h, 1);
	write(1, "\nimaxchar: ", 11);
	h = brain.imaxchar;
	printf("%d\n", h);
	write(1, "imaxcharzero: ", 14);
	h = brain.imaxcharzero+48;
	write(1, &h, 1);
	write(1, "\nstrin: ", 8);
	int a = 0;
	while (brain.strin[a])
	{
		write(1, &brain.strin[a], 1);
		a++;
	}
	write(1, "\ntotalen: ", 10);
	h = brain.totalen + 40;
	write(1, &h, 1);
	write(1, "\n\n", 2);
}


t_brain	brainwash(t_brain brain)
{
	brain.ctype = '-';
	brain.bzero = 0;
	brain.bneg = 0;
	brain.bperiod = 0;
	brain.bplus = 0;
	brain.bspace = 0;
	brain.bhash = 0;
	brain.iminchar = 0;
	brain.imincharzero = 0;
	brain.imaxchar = 0;
	brain.imaxcharzero = 0;
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

/*
#include <limits.h>
int main()
{
	int z;
	char m;

	m = '3';
	z = 0;
	write(1, "\nYours: ", 8);
	int a = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	write(1, "\n\nOrgnl: ", 9);
	int b = printf(" %.s ", "qwertyuiop");
	printf("\n\nft_printf returned: %d", a);
	printf("\n   printf returned: %d", b);
	if (a == b)
		printf("\n\nBoth printf's RETURNED the same value (check printed values)\n\n");
	else
		printf("\n\nSomething went wrong :(\n\n");
}*/

// gcc -Wall -Werror -Wextra ft_printf.c ft_s.c ft_c.c ft_id.c ft_x.c ft_p.c ft_u.c ft_paramdetector2.c ft_printf.h ft_itoa.c ft_libft.c && ./a.out && rm a.out
// gcc ft_printf.c ft_s.c ft_c.c ft_id.c ft_x.c ft_p.c ft_u.c ft_paramdetector2.c ft_printf.h ft_itoa.c ft_libft.c && ./a.out && rm a.out