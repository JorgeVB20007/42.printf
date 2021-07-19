# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 18:16:53 by jvacaris          #+#    #+#              #
#    Updated: 2021/07/19 18:16:57 by jvacaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			ft_s.c \
			ft_c.c \
			ft_p.c \
			ft_id.c \
			ft_x.c \
			ft_u.c \
			ft_paramdetector.c \
			ft_libft.c \
			ft_atoi.c \
			ft_itoa.c \


OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all:		${NAME}
${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}
bonus:		${OBJS} ${OBJSB}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}
clean:
	@${RM} ${OBJS} ${OBJSB}
fclean:		clean
	@${RM} ${NAME}
re:		fclean all
