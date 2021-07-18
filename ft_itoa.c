/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:15:22 by jvacaris          #+#    #+#             */
/*   Updated: 2021/06/04 19:15:26 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*minnumber(int n)
{
	char	*a;

	if (n == -2147483648)
	{
		a = malloc(11);
		a[0] = '2';
		a[1] = '1';
		a[2] = '4';
		a[3] = '7';
		a[4] = '4';
		a[5] = '8';
		a[6] = '3';
		a[7] = '6';
		a[8] = '4';
		a[9] = '8';
		a[10] = 0;
	}
	else
	{
		a = malloc(2);
		a[0] = '0';
		a[1] = 0;
	}
	return (a);
}

int	checklong(int n)
{
	int	p;

	p = 0;
	while (n != 0)
	{
		n = n / 10;
		p++;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		largo;
	char	*result;

	neg = 0;
	largo = 0;
	if (n == -2147483648 || n == 0)
		return (minnumber(n));
	else if (n < 0)
		neg = 1;
	if (neg == 1)
		n = n * -1;
	largo = checklong(n);
	result = malloc(largo + neg + 1);
	if (!result)
		return (0);
	result[largo + neg] = 0;
	result[0] = '-';
	while (n > 0)
	{
		result[largo - !neg] = (n % 10) + 48;
		n = n / 10;
		largo--;
	}
	return (result);
}

int	checkulong(unsigned int n)
{
	int	p;

	p = 0;
	while (n != 0)
	{
		n = n / 10;
		p++;
	}
	return (p);
}

char	*ft_utoa(unsigned int n)
{
	int		largo;
	char	*result;

	if (n == 0)
		return (ft_strdup("0"));
	largo = 0;
	largo = checkulong(n);
	result = malloc(largo + 1);
	if (!result)
		return (0);
	result[largo] = 0;
	while (n > 0)
	{
		result[largo - 1] = (n % 10) + 48;
		n = n / 10;
		largo--;
	}
	return (result);
}