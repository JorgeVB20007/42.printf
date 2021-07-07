#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void turn_to_hex(void)
{
	char	hextorage[8];
	int		a;
	int		temp;
	char	tempchar;

	a = 0;
	temp = va_arg(arguments, int);
	while (temp != 0)
	{
		if (temp % 16 > 9)
		{
			if (ctype == 'x')
				tempchar = ((temp % 16) + 87);
			else
				tempchar = ((temp % 16) + 55);
		}
		else
			tempchar = temp % 16;
		hextorage[a] = tempchar;
	}
	write(1, &hextorage, a);
}