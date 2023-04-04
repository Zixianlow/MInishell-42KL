# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 11:27:38 by lzi-xian          #+#    #+#              #
#    Updated: 2023/03/30 15:40:28 by lzi-xian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
SRC_DIR     =    srcs/
OBJS_DIR    =    objs/
MAN_FILES	=	minishell					\
				ft_sigaction				\
				ft_cmd_with_builtin			\
				ft_close_pipe_wait_child	\
				ft_get_pipe					\
				ft_execve_cmd				\
				ft_builtin_env_pwd			\
				ft_builtin_cd				\
				ft_builtin_echo
OBJS 		=	$(SRCS:.c=.o)
SRCS        =	$(addprefix $(SRC_DIR), $(addsuffix .c, $(MAN_FILES)))
OBJS        =	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(MAN_FILES)))
ARCR		= 	ar cr 
RMRF		=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
GCC			=	gcc
RLLIB		=	-L /usr/local/opt/readline/lib
RLINC       =   -I /usr/local/opt/readline/include


all:
	@mkdir -p $(OBJS_DIR)
	@make $(NAME)

$(OBJS_DIR)%.o:	$(SRC_DIR)%.c
	@$(GCC) ${RLINC} -c $< -o $@

$(NAME):	${OBJS}
	${GCC} ${CFLAGS} ${OBJS} ${RLLIB} ${RLINC} libft/libft.a -lcurses -lreadline -o $(NAME) -fsanitize=address -g3
	
clean:
	${RMRF} ${OBJS} ${OBJS_DIR}

fclean:	clean
	${RMRF}	$(NAME)

re:	fclean all