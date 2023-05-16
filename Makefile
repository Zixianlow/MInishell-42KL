# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 11:27:38 by lzi-xian          #+#    #+#              #
#    Updated: 2023/05/16 15:05:11 by lzi-xian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
SRC_DIR     =   srcs/
OBJS_DIR    =   objs/
MAN_FILES	=	minishell					\
				ft_utils1					\
				ft_utils2					\
				ft_utils3					\
				ft_utils_cd					\
				ft_utils_export				\
				ft_utils_exportii			\
				ft_child_cmd				\
				ft_parent_cmd				\
				ft_utils_file				\
				ft_utils_line				\
				ft_utils_echo				\
				ft_utils_pipeline			\
				ft_sigaction				\
				ft_cmd_with_builtin			\
				ft_close_pipe_wait_child	\
				ft_free_list				\
				ft_get_pipe					\
				ft_execve_cmd				\
				ft_remove_in_out			\
				ft_builtin_env_pwd			\
				ft_builtin_cd				\
				ft_builtin_export			\
				ft_builtin_unset			\
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