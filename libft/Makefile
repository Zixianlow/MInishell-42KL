# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 17:31:32 by lzi-xian          #+#    #+#              #
#    Updated: 2023/01/11 12:29:30 by lzi-xian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c  \
				ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c	\
				ft_printf/ft_atoi.c ft_printf/ft_chk_init_percent_flags.c \
				ft_printf/ft_init_set_flags.c \
				ft_printf/ft_print_front_back.c ft_printf/ft_printf.c \
				ft_printf/ft_printing.c ft_printf/ft_putchar.c	\
				ft_printf/ft_putchar_l.c ft_printf/ft_puthexa.c	\
				ft_printf/ft_puthexa_l.c ft_printf/ft_putnbr.c	\
				ft_printf/ft_putnbr_l.c ft_printf/ft_putptr.c	\
				ft_printf/ft_putptr_l.c ft_printf/ft_putpercent.c	\
				ft_printf/ft_putstr.c ft_printf/ft_putstr_l.c	\
				ft_printf/ft_putunsign.c ft_printf/ft_putunsign_l.c
BONUS		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS		=	${SRCS:.c=.o}
BONUS_OBJS	=	${BONUS:.c=.o}
NAME		=	libft.a
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
	${RMRF} ${OBJS} ${BONUS_OBJS}

fclean:	clean
	${RMRF} ${NAME}

bonus:	${BONUS_OBJS}
	${ARCR} ${NAME} ${BONUS_OBJS}

re:	fclean all bonus