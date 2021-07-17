SRCS	=	ft_printf.c \
			ft_s.c \
			ft_c.c \
			ft_p.c \
			ft_id.c \
			ft_paramdetector2.c \
			ft_libft.c \
			ft_atoi.c \




SRCSB	=	test.c \

OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}
NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all:		${NAME}
${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}
bonus:		${OBJS} ${OBJSB}
			ar rc ${NAME} ${OBJS} ${OBJSB}
			ranlib ${NAME}
clean:
	@${RM} ${OBJS} ${OBJSB}
fclean:		clean
	@${RM} ${NAME}
re:		fclean all
