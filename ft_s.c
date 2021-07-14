#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_brain	spaceandcount(t_brain brain)
{
	write(1, " ", 1);
	brain.totalen++;
	return (brain);
}
/************************************
 *                                  *
 *  This has to be changed so the   *
 *  string shortening is the first  *
 *   thing to happen. Make a new    *
 *   variable (string2) to place    *
 *    the new shortened string.     *
 *                                  *
 *                 ||               *
 *                 ||               *
 *              \\ || //            *
 *               \\||//             *
 *                \  /              *
 *                 \/                *
 ************************************/

t_brain	ft_s(t_brain brain)
{
	int		dif;
	char	*string = NULL;
	printf(">>%d<<", brain.totalen);
//	write(1, "It's a string!", 14);
	string = va_arg (*brain.args, char *);
	if (ft_strlen(string) < brain.iminchar && !brain.bneg)
	{
		dif = brain.iminchar;
		while (dif-- - ft_strlen(string))
			brain = spaceandcount(brain);
	}
	if ((ft_strlen(string) > brain.imaxchar && brain.imaxchar) || brain.imaxcharzero)
	{
		dif = 0;
		if (!brain.bneg && brain.imaxchar < brain.iminchar)
			while (ft_strlen(string) - dif++ > brain.imaxchar)
				spaceandcount(brain);
		dif = 0;
		while (dif < brain.imaxchar)
		{
			write(1, &string[dif], 1);
			brain.totalen++;
			dif++;
		}
		dif = 0;
		if (brain.bneg && brain.imaxchar < brain.iminchar)
			while (ft_strlen(string) - dif++ > brain.imaxchar)
				spaceandcount(brain);
	}
	if (ft_strlen(string) < brain.iminchar && brain.bneg)
	{
		dif = brain.iminchar;
		while (dif-- - ft_strlen(string))
			brain = spaceandcount(brain);
	}
	dif = 0;
	if (ft_strlen(string) < brain.imaxchar && ft_strlen(string) > brain.iminchar)
	{
		while (string[dif])
		{
			write(1, &string[dif], 1);
			brain.totalen++;
			dif++;
		}
	}
	printf(">>.%d.<<", brain.totalen);
	return (brain);
}