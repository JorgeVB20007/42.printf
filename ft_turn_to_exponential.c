//#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

char	*turn_to_exponential(float num)
{
	int		neg;
	int		exp;
	float	newnum;

	neg = 0;
	exp = 0;
	newnum = num;
	if (num < 0.0)
	{
		neg = 1;
	}
	else if (num < 1.0)
	{
		while (newnum < 1.0)
		{
			newnum = newnum * 10;
			exp--;
		}
	}
	else if (num >= 10.0)
	{
		while (newnum >= 10.0)
		{
			newnum = newnum / 10;
			exp++;
		}
	}
	char c;
	if (exp >= 0)
		c = '+';
	else
		c = '-';
	if (neg)
		newnum = newnum * -1;
	printf("Yours: %fe%c%d\n", newnum, c, exp);
	printf("Orign: %e\n", num);
	printf("\a");
	return(NULL);
}

int main()
{
	char *a;

	a = turn_to_exponential(5583455665.0068465);
}