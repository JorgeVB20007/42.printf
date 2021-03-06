/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:16:38 by jvacaris          #+#    #+#             */
/*   Updated: 2021/07/19 18:16:39 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_brain	ft_u(t_brain brain)
{
	unsigned int	thenum;
	unsigned int	thenewnum;
	char			*thestr;

	thenum = va_arg (*brain.args, unsigned int);
	thenewnum = thenum;
	thestr = ft_utoa(thenewnum);
	while (ft_strlen(thestr) < brain.imxchr)
		thestr = addazero(thestr);
	brain = int_string_printer(brain, thestr);
	return (brain);
}

t_brain	ft_percent(t_brain brain)
{
	char		*thestr;

	thestr = malloc(2);
	thestr[0] = '%';
	thestr[1] = 0;
	brain = int_string_printer(brain, thestr);
	return (brain);
}
