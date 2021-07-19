#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_brain	ft_p(t_brain brain)
{
	unsigned long long int	b;
	char					*str;
	int						h;

	b = va_arg(*brain.args, unsigned long long);
	if (b)
		str = turn_to_hex(b, 0);
	else
		str = ft_strdup("0");
	h = 0;
	str = addazero(str);
	h = 0;
	str[0] = 'x';
	h = 0;
	str = addazero(str);
	h = 0;
	brain = int_string_printer(brain, str);
	return (brain);
}
