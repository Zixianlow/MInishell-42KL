/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:50:59 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/26 20:56:29 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <dirent.h> 
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_mini
{
	int				pipe_count;
	int				**fd;
	int				**here_fd;
	int				here_id;
	int				here_count;
	pid_t			pid;
	pid_t			pid2;
	char			*heredoc;
	char			*here_line;
	char			*res;
	char			*line;
	char			*cmd_path;
	char			**dir_list;
	char			**env;
	char			*env_path;
	char			**path_list;
	char			**file;
	char			**line_list;
	char			***pipe_line_list;
}	t_mini;

int		ft_check_quote(char *line, int q);
void	ft_cmd(t_mini	*mini, char **line);
void	ft_print_env(char **env);
void	ft_pwd(void);
void	ft_echo(t_mini *mini, char **list);
void	ft_cd(t_mini *mini, char **env, char **line);
int		ft_execve_cmd(t_mini	*mini, char **line);
void	ft_get_here_pipe(t_mini *mini);
void	ft_create_pipes_fd(t_mini *mini);
void	ft_close_pipe_wait_child(t_mini *mini, int i);

#endif