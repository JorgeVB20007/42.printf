#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_brain
{
	const char	*strin;
	int			loc;
	char		ctype;
	int			bzero;
	int			bneg;
	int			bperiod;
	int			bplus;
	int			bspace;
	int			bhash;
	int			bemergencybreak;
	int			basterisk;
	int			basterisktwo;
	int			iminchar;
	int			imaxchar;
	int			imincharzero;
	int			imaxcharzero;
	int			totalen;
}	t_brain;

int		ft_printf(const char *masstr, ...);
char	*ft_itoa(int n);
char	*turn_to_exponential(int num);
int		ft_isalpha(char c);
int		ft_strlen(char *s);
int		ft_intlen(int a);
void	spacer(int a);
int		ft_isdigit(char c);
void	paramdetector(void);
void	ft_s(void);

#endif