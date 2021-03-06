/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramdetector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:15:55 by jvacaris          #+#    #+#             */
/*   Updated: 2021/07/19 18:15:57 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static t_brain	typesorter(t_brain brain)
{
	if (brain.ctype == 's')
		brain = ft_s(brain);
	if (brain.ctype == 'c')
		brain = ft_c(brain);
	if (brain.ctype == 'd' || brain.ctype == 'i')
		brain = ft_id(brain);
	if (brain.ctype == 'u')
		brain = ft_u(brain);
	if (brain.ctype == 'p')
		brain = ft_p(brain);
	if (brain.ctype == 'x' || brain.ctype == 'X')
		brain = ft_x(brain);
	if (brain.ctype == '%')
		brain = ft_percent(brain);
	return (brain);
}

static t_brain	paramdetectortwo(t_brain brain)
{
	if (ft_isalpha(brain.strin[brain.loc]) || brain.strin[brain.loc] == '%')
		brain.ctype = brain.strin[brain.loc];
	else if (brain.strin[brain.loc] == '-')
		brain.bneg = 1;
	else if (brain.strin[brain.loc] == '0' && !brain.bdot && !brain.imnchr)
		brain.bzero = 1;
	else if (brain.strin[brain.loc] == '.')
		brain.bdot = 1;
	else if (brain.strin[brain.loc] == '+')
		brain.bplus = 1;
	else if (brain.strin[brain.loc] == ' ')
		brain.bspace = 1;
	else if (brain.strin[brain.loc] == '#')
		brain.bhash = 1;
	else if (ft_isdigit(brain.strin[brain.loc]) && !brain.bdot)
		brain.imnchr = brain.imnchr * 10 + (brain.strin[brain.loc] - 48);
	else if (ft_isdigit(brain.strin[brain.loc]) && brain.bdot)
		brain.imxchr = brain.imxchr * 10 + (brain.strin[brain.loc] - 48);
	else
		brain.bemergencybreak = 1;
	brain.loc++;
	return (brain);
}

t_brain	paramdetector(t_brain brain)
{
	brain.loc++;
	while (brain.ctype == '-' && !brain.bemergencybreak)
	{
		brain = paramdetectortwo(brain);
	}
	if (!brain.bemergencybreak)
		brain = typesorter(brain);
	return (brain);
}
