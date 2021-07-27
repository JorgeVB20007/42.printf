/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:13:42 by jvacaris          #+#    #+#             */
/*   Updated: 2021/07/19 18:13:44 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static char	*add_new_hex_char(char *oldstr, int new, int caps)
{
	char	*newstr;
	int		a;

	a = 0;
	newstr = malloc(ft_strlen(oldstr) + 2);
	if (new < 10)
		newstr[a] = new + 48;
	else if (!caps)
		newstr[a] = new + 87;
	else
		newstr[a] = new + 55;
	a++;
	while (oldstr[a - 1])
	{
		newstr[a] = oldstr[a - 1];
		a++;
	}
	newstr[a] = 0;
	free(oldstr);
	return (newstr);
}

char	*turn_to_hex(unsigned long long thenum, int caps)
{
	int		remainders;
	char	*thestr;

	thestr = malloc(1);
	thestr[0] = 0;
	while (thenum > 0)
	{
		remainders = thenum % 16;
		thestr = add_new_hex_char(thestr, remainders, caps);
		thenum = thenum / 16;
	}
	return (thestr);
}

t_brain	ft_x(t_brain brain)
{
	unsigned long long int	b;
	char					*str;

	b = va_arg(*brain.args, unsigned int);
	if (!b)
		str = ft_strdup("0");
	else if (brain.ctype == 'x')
		str = turn_to_hex(b, 0);
	else
		str = turn_to_hex(b, 1);
	if (brain.bhash && b)
	{
		str = addazero(str);
		if (brain.ctype == 'x')
			str[0] = 'x';
		else if (brain.ctype == 'X')
			str[0] = 'X';
		str = addazero(str);
	}
	while (ft_strlen(str) < brain.imxchr)
		str = addazero(str);
	brain = int_string_printer(brain, str);
	return (brain);
}
