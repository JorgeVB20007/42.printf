#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

char	*add_new_hex_char(char *oldstr, int new, int caps)
{
	char	*newstr;
	int		a;


	a = 0;
	newstr = malloc(ft_strlen(oldstr + 2));
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

char	*turn_to_hex(unsigned long long int thenum, int caps)
{
	int		remainders;
	char	*thestr;

	thestr = malloc(1);
	while (thenum > 0)
	{
		remainders = thenum % 16;
		thestr = add_new_hex_char(thestr, remainders, caps);
		thenum = thenum / 16;
	}
	return (thestr);
}


/************************************************
*												*
*	INVESTIGATE WHY printf("%p") ABBREVIATES	*
*	  HEX CODE (ffffffff... --> 7ff...) AND 	*
*	           HOW TO WORK WITH IT				*
*												*
*************************************************/