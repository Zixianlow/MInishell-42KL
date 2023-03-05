# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 11:27:38 by lzi-xian          #+#    #+#              #
#    Updated: 2023/03/04 15:01:46 by lzi-xian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
SRCS		=	minishell.c			\
				ft_cd.c				\
				ft_echo.c
ARCR		= 	ar cr
RMRF		=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
GCC			=	gcc

$(NAME):
	${GCC} ${CFLAGS} ${SRCS} libft/libft.a -lcurses -lreadline -o $(NAME)

all:	$(NAME)

clean:
	${RMRF} $(NAME)

fclean:	clean
	${RMRF}

re:	fclean all