/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:50:59 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/15 20:59:34 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <dirent.h> 
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_mini
{
	int				pipe_count;
	int				**fd;
	int				**here_fd;
	int				here_count;
	int				here_yes;
	int				here_id;
	int				temp_in;
	int				temp_out;
	int				err;
	pid_t			pid;
	pid_t			pid2;
	char			*heredoc;
	char			*here_str;
	char			*here_line;
	char			*res;
	char			*line;
	char			*cmd_path;
	char			**env;
	char			*env_path;
	char			**path_list;
	char			**file;
	char			**line_list;
	char			***pipe_line;
	char			***echo_line;
}	t_mini;

int		ft_check_quote(char *line, int q);
void	ft_cmd(t_mini	*mini, char **line, char **echo);
void	ft_print_env(char **env);
void	ft_pwd(char **line);
void	ft_echo(t_mini *mini, char **list);
void	ft_cd(t_mini *mini, char **env, char **line);
void	ft_execve_cmd(t_mini *mini, char **line);
void	ft_get_here_pipe(t_mini *mini);
void	ft_create_pipes_fd(t_mini *mini);
void	ft_close_pipe_wait_child(t_mini *mini, int i);
void	ft_export(t_mini *mini, char **line);
void	ft_unset(t_mini *mini, char **line);
void	ft_print_ent(t_mini *mini, char *line, int *i);
void	sig_handler(int signo);
int		ft_check_quote(char *line, int q);
void	ft_dup_rest_of_line(char *line, int i, char **temp, int *len);
char	*ft_env_to_line(char *line, char **env, int i);
void	free_cd(char **new, char **old);
void	ft_swap(char **a, char **b);
int		ft_strcmp(char *s1, char *s2);
char	*checkav(char *line);
void	ft_change_sp_to_tab(char *s);
char	*ft_treat_line(char *line);
void	ft_treat_pipe_line(char ***pipe_line, char **env, t_mini *mini);
int		ft_calc_list_size(t_mini *mini, int i);
char	**ft_remove_in_out_from_list(char ***list, int l);
void	ft_handle_in_out_file(t_mini *mini, int n);
int		ft_check_parent_cmd(t_mini *mini);
void	ft_parent_cmd(t_mini *mini, char **line);
void	ft_child_cmd(t_mini *mini, int *i);
void	print_default(t_mini *mini);
char	*ft_line_dup(char *s);
char	**ft_remove_in_out_from_list(char ***list, int l);
void	ft_handle_in_out_file(t_mini *mini, int n);
void	ft_get_pipe_line(t_mini *mini);
char	*charcmp(char *pipe, int input, char *new);
void	ft_parent_cmd_error(t_mini *mini, char *s);
void	ft_free_echo_list(t_mini *mini);
void	ft_free_pipe_list(t_mini *mini);
int		ft_len_to_eq(char *line);
void	print_export(t_mini *mini);
int		check_now(char *line);
int		check_copy(char **line);
int		ft_chk_exist(t_mini *mini, char *line);
int		check_now_d(char *line, t_mini *mini);
int		ft_skip_redir(char **list, int *i);
void	ft_check_n(char **s, int *i, int *c);

#endif