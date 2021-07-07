#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void paramdetector(void)
{
	int completed;

	completed = 0;
	while (!completed)
	{
		if (ft_isalpha(brain.strin[loc]))
		{
			completed++;
			brain.ctype = brain.strin[loc];
		}
		else if (brain.strin[loc] == '-' && !bperiod && !iminchar && !basterisk)
			brain.bneg = 1;
		else if (brain.strin[loc] == '-')
			error(loc, "'-' cannot be placed here.");
		else if (brain.strin[loc] == '0' && !bperiod && !iminchar && !basterisk)
			brain.bzero = 1;
		else if (brain.strin[loc] == '0' && (basterisk && !bperiod || basterisktwo))
			error(loc, "'0' cannot be placed here.");
		else if (brain.strin[loc] == '0' && bperiod)
			if (!brain.imaxchar)
				brain.imaxcharzero = 1;
			else
				brain.imaxchar = brain.imaxchar * 10;
		else if (brain.strin[loc] == '0')
			if (!brain.iminchar)
				brain.imincharzero = 1;
			brain.iminchar = brain.iminchar * 10;
		else if (brain.strin[loc] == '*' && !bperiod && !iminchar)
			brain.basterisk = 1;
		else if (brain.strin[loc] == '*' && bperiod && !imaxchar)
			brain.basterisktwo = 1;
		else if (brain.strin[loc] == '*' && basterisk && basterisktwo)
			error(loc, "'*' has been used more than twice.")
		else if (brain.strin[loc] == '*')
			error(loc, "'*' cannot be placed here.");
		else if (brain.strin[loc] == '.' && brain.bperiod)
			error(loc, "Duplicated '.'");
		else if (brain.strin[loc] == '.')
			brain.bperiod = 1;
		else if (ft_isdigit(brain.strin[loc]) && !bperiod)
			brain.iminchar = brain.iminchar * 10 + brain.strin[loc] + 48;
		else if (ft_isdigit(brain.strin[loc]) && bperiod)
			brain.imaxchar = brain.imaxchar * 10 + brain.strin[loc] + 48;


	}
}

void error(int a, char *errmess)
{
	int b;

	b = 0;
	write(1, "ERROR: ", 7);
	while (errmess[b])
	{
		write(1, &errmess[b], 1);
		b++;
	}
	b = 0;
	write(1, "\n>> printf(\"", 12);
	while (brain.strin[b])
	{
		write(1, &brain.strin[b], 1);
		b++;
	}
	write(1, "\" ...\n           ", 16);
	b = 0;
	while (a < b - 1)
		write(1, " ", 1);
	write(1)
}