#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	printbrain(void)
{
	t_brain	brain;
	int h;
	write(1, "\nctype: '", 9);
	write(1, &brain.ctype, 1);
	write(1, "'\nbzero: ", 9);
	h = brain.bzero+48;
	write(1, &h, 1);
	write(1, "\nbneg: ", 7);
	h = brain.bneg+48;
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
	write(1, "\nbasterisk: ", 12);
	h = brain.basterisk+48;
	write(1, &h, 1);
	write(1, "\nbasterisktwo: ", 15);
	h = brain.basterisktwo+48;
	write(1, &h, 1);
	write(1, "\niminchar: ", 11);
	h = brain.iminchar+48;
	write(1, &h, 2);
	write(1, "\nimincharzero: ", 15);
	h = brain.imincharzero+48;
	write(1, &h, 1);
	write(1, "\nimaxchar: ", 11);
	h = brain.imaxchar+48;
	write(1, &h, 2);
	write(1, "\nimaxcharzero: ", 15);
	h = brain.imaxcharzero+48;
	write(1, &h, 1);
	write(1, "\nstrin: ", 8);
	int a = 0;
	while (brain.strin[a])
	{
		write(1, &brain.strin[a], 1);
		a++;
	}
	write(1, "\n\n", 2);
	
}


void	brainwash(void)
{
	t_brain	brain;

	brain.ctype = '-';
	brain.bzero = 0;
	brain.bneg = 0;
	brain.bperiod = 0;
	brain.bplus = 0;
	brain.bspace = 0;
	brain.bhash = 0;
	brain.basterisk = 0;
	brain.basterisktwo = 0;
	brain.iminchar = 0;
	brain.imincharzero = 0;
	brain.imaxchar = 0;
	brain.imaxcharzero = 0;
}

void	printez(void)
{
	t_brain	brain;

	printf("\n\n**%d**\n\n", brain.loc);
//	printf("\n..\n%s %d\n..\n", brain.strin, brain.loc);
	write(1, &brain.loc, 1);
	write(1, &brain.strin[brain.loc], 1);
	write(1, "a", 1);
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
}

int	ft_printf(const char *masstr, ...)
{
	t_brain	brain;
	va_list	arguments;

	brain.strin = ft_strdup(masstr);
	brain.bemergencybreak = 0;
	brain.loc = 0;
	brain.totalen = 0;
	va_start(arguments, masstr);
	while (!brain.bemergencybreak)
	{
		brainwash();
		write(1, "1", 1);
		printez();
		write(1, "2", 1);
		if (!brain.bemergencybreak)
			paramdetector();
		printbrain();
	}
	va_end(arguments);
	return (brain.totalen);
}


int main()
{
	int a = ft_printf("Hello World");
	printf("  %d", a);
}