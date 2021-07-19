/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:16:25 by jvacaris          #+#    #+#             */
/*   Updated: 2021/07/19 18:16:27 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	spacer(int a)
{
	while (a > 0)
	{
		write(1, " ", 1);
		a--;
	}
}

t_brain	spaceandcount(t_brain brain)
{
	if (brain.ctype == 'd' || brain.ctype == 'i' || brain.ctype == 'u')
	{
		if (brain.bzero && !brain.bdot)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	else if (brain.ctype == 'x' || brain.ctype == 'X' || brain.ctype == '%')
	{
		if (brain.bzero && !brain.bdot)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	else
		write(1, " ", 1);
	brain.totalen++;
	return (brain);
}

static char	*stringtrimmer(t_brain brain, char *inistr)
{
	char	*newstring;
	int		a;

	a = 0;
	if (!inistr)
		inistr = ft_strdup("(null)");
	if (brain.bdot && !brain.imxchr && !brain.imxchrzro)
		return (ft_strdup(""));
	if ((ft_strlen(inistr) > brain.imxchr && brain.imxchr) || brain.imxchrzro)
	{
		newstring = malloc (brain.imxchr + 1);
		while (a < brain.imxchr)
		{
			newstring[a] = inistr[a];
			a++;
		}
		newstring[a] = 0;
		return (newstring);
	}
	else
		return (ft_strdup(inistr));
}

t_brain	ft_s(t_brain brain)
{
	int		dif;
	char	*string;

	string = stringtrimmer(brain, va_arg (*brain.args, char *));
	if (ft_strlen(string) < brain.imnchr && !brain.bneg)
	{
		dif = brain.imnchr;
		while (dif-- - ft_strlen(string))
			brain = spaceandcount(brain);
	}
	dif = 0;
	while (string[dif])
	{
		write(1, &string[dif], 1);
		brain.totalen++;
		dif++;
	}
	if (ft_strlen(string) < brain.imnchr && brain.bneg)
	{
		dif = brain.imnchr;
		while (dif-- - ft_strlen(string))
			brain = spaceandcount(brain);
	}
	free (string);
	return (brain);
}
