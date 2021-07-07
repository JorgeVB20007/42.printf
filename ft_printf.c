#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	brainwash(void)
{
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
	while (*brain.strloc && *brain.strloc != '%')
	{
		write(1, brain.strloc, 1);
		brain.strloc = brain;
	}
	if (!*brain.strloc)
	{
		brain.bemergencybreak = 1;
	}
}

int ft_printf(const char *masstr, ...)
{
	va_list	arguments;

	brain.strloc = masstr;
	brain.bemergencybreak = 0;
	va_start(arguments, masstr);
	while (!bemergencybreak)
	{
		brainwash(void);
		printez(void);
		if (!brain.bemergencybreak)
			paramdetector(void);
	}

/*	va_start(arguments, masstr);
	a = 0;
	while (a < 5)
	{
		value = va_arg(arguments,char *);
		printf("%d: %s\n", a, value);
		a++;
	}
	va_end(arguments);*/

	
	a = 0;
	
	va_end(arguments);
	return (0);
}


int args_in_str_chk(const char *masstr)
{
	int a;
	int cntr;

	a = 0;
	cntr = 0;
	while (masstr[a])
	{
		if (masstr[a] == '%')
		{
			cntr++;
			if (masstr[a + 1] == '%')
				a++;
		}
		a++;
	}
	return (0);
}

int	main(void)
{
	printf("%s\n", 'd');
	printf("**%-5d**\n", 99);
	ft_printf("Aquí una string: %s\nAquí un char: %c\nAquí un int: %i\nAquí un exponencial: %e\n", "Weeeeee", '@', 54321);
}
