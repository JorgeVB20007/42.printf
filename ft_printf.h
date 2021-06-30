
#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *masstr, ...);
char	*ft_itoa(int n);
char	*turn_to_exponential(int num);

#endif