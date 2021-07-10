#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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

	brain.strin = masstr;
	brain.bemergencybreak = 0;
	va_start(arguments, masstr);
	while (!brain.bemergencybreak)
	{
		brainwash();
		printez();
		if (!brain.bemergencybreak)
			paramdetector();
	}
	va_end(arguments);
	return (brain.totalen);
}


int main()
{
	int a = ft_printf("Hello");
	printf("  %d", a);
}