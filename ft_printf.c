#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


void	printstr(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		write(1, &str[a], 1);
		a++;
	}
}


int ft_printf(const char *masstr, ...)
{
	int a;
	char *value;
	va_list	arguments;

/*	va_start(arguments, masstr);
	a = 0;
	while (a < 5)
	{
		value = va_arg(arguments,char *);
		printf("%d: %s\n", a, value);
		a++;
	}
	va_end(arguments);*/

	va_start(arguments, masstr);
	a = 0;
	while (masstr[a])
	{
		if (masstr[a] != '%')
			write(1, &masstr[a], 1);
		else if (masstr[a + 1] == '%')
		{
			write(1, "%%", 1);
			a++;
		}
		else if (masstr[a + 1] == 's')
		{
			value = va_arg(arguments, char *);
			printstr(value);
			a++;
		}
		else if (masstr[a + 1] == 'c')
		{
			value = va_arg(arguments, char *);
			write(1, &value, 1);
			a++;
		}
		else if (masstr[a + 1] == 'd')
		{
			value = ft_itoa(va_arg(arguments, int));
			printstr(value);
			a++;
		}
			
		a++;
	}
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
	printf("%e\n", 123456789.0);
	ft_printf("Aquí una string: %s\nAquí un char: %c\nAquí un int: %d\nAquí un exponencial: %e\n", "Weeeeee", '@', 54321);
}
