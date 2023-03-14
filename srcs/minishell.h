/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:50:59 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/13 17:45:21 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <dirent.h> 
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_mini
{
	int		pipe_count;
	char	*res;
	char	*line;
	char	*cmd_path;
	char	**dir_list;
	char	**env;
	char	*env_path;
	char	**path_list;
	char	**file;
	char	**line_list;
	char	***pipe_line_list;
}	t_mini;

void	ft_echo(t_mini *mini, char **list);
int		ft_check_quote(char *line, int q);
void	ft_cd(t_mini *mini, char **env, char **line);
void	ft_execve_cmd(t_mini	*mini, char **line);

#endif