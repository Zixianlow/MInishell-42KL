# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 20:02:28 by lzi-xian          #+#    #+#              #
#    Updated: 2022/11/16 18:10:03 by lzi-xian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c ft_chk_init_percent_flags.c ft_init_set_flags.c \
				ft_print_front_back.c ft_printf.c ft_printing.c ft_putchar.c \
				ft_putchar_l.c ft_puthexa.c ft_puthexa_l.c ft_putnbr.c \
				ft_putnbr_l.c ft_putptr.c ft_putptr_l.c ft_putpercent.c\
				ft_putstr.c ft_putstr_l.c ft_putunsign.c ft_putunsign_l.c
OBJS		=	${SRCS:.c=.o}
NAME		=	libftprintf.a
ARCR		= 	ar cr
RMRF		=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
GCC			=	gcc

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	${ARCR} ${NAME} ${OBJS}

all:	$(NAME)

clean:
	${RMRF} ${OBJS}

fclean:	clean
	${RMRF} ${NAME}

re:	fclean all

bonus: re
