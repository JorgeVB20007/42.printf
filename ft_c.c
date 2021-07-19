/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:14:53 by jvacaris          #+#    #+#             */
/*   Updated: 2021/07/19 18:14:54 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_brain	ft_c(t_brain brain)
{
	int		dif;
	char	cara;

	cara = va_arg (*brain.args, int);
	dif = 0;
	while (dif + 1 < brain.imnchr && !brain.bneg)
	{
		write(1, " ", 1);
		brain.totalen++;
		dif++;
	}
	write(1, &cara, 1);
	brain.totalen++;
	while (dif + 1 < brain.imnchr && brain.bneg)
	{
		write(1, " ", 1);
		brain.totalen++;
		dif++;
	}
	return (brain);
}
