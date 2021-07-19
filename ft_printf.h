#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_brain
{
	char		*strin;
	int			loc;
	char		ctype;
	int			bzero;
	int			bneg;
	int			bdot;
	int			bplus;
	int			bspace;
	int			bhash;
	int			bemergencybreak;
	int			imnchr;
	int			imxchr;
	int			imnchrzro;
	int			imxchrzro;
	int			totalen;
	va_list		*args;
}	t_brain;

int		ft_printf(const char *masstr, ...);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*turn_to_exponential(int num);
int		ft_isalpha(char c);
int		ft_strlen(char *s);
int		ft_intlen(int a);
void	spacer(int a);
int		ft_isdigit(char c);
t_brain	paramdetector(t_brain brain);
t_brain	ft_s(t_brain brain);
t_brain	ft_c(t_brain brain);
t_brain	ft_id(t_brain brain);
t_brain	ft_p(t_brain brain);
t_brain	ft_u(t_brain brain);
t_brain	ft_x(t_brain brain);
t_brain	ft_percent(t_brain brain);
char	*ft_strdup(const char *s1);
t_brain	spaceandcount(t_brain brain);
char	*turn_to_hex(unsigned long long int thenum, int caps);
t_brain	int_string_printer(t_brain brain, char *string);
char	*addazero(char *str);

#endif