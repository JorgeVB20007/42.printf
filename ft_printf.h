#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

struct s_brain
{
	char	*strloc;
	char	ctype;
	int		bzero;
	int		bneg;
	int		bperiod;
	int		bplus
	int		bemergencybreak;
	int		basterisk;
	int		basterisktwo;
	int		iminchar;
	int		imaxchar;
};

int		ft_printf(const char *masstr, ...);
char	*ft_itoa(int n);
char	*turn_to_exponential(int num);

#endif