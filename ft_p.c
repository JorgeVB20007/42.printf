#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


t_brain	ft_p(t_brain brain)
{
	unsigned long long int	b;
	char					*str;

	b = (unsigned long long int)va_arg(*brain.args, int);

	str = turn_to_hex(b, 0);
	brain = int_string_printer(brain, "0x");
	brain = int_string_printer(brain, str);
	return (brain);
}


/************************************************
*												*
*	INVESTIGATE WHY printf("%p") ABBREVIATES	*
*	 HEX CODE (ffffffff... --> 7ffe...) AND 	*
*			  HOW TO WORK WITH IT 				*
*												*
*************************************************/