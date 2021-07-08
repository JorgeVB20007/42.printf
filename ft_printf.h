#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_brain
{
	char	*strin;
	char	*strout;
	int		loc;
	char	ctype;
	int		bzero;
	int		bneg;
	int		bperiod;
	int		bplus;
	int		bspace;
	int		bhash;
	int		bemergencybreak;
	int		basterisk;
	int		basterisktwo;
	int		iminchar;
	int		imaxchar;
}	t_brain;

int		ft_printf(const char *masstr, ...);
char	*ft_itoa(int n);
char	*turn_to_exponential(int num);

#endif