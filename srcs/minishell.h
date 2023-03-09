/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:50:59 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/08 19:26:48 by lzi-xian         ###   ########.fr       */
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
	char	**env;
	char	*env_path;
	char	**path_list;
	char	**file;
	char	**line_list;
	char	***pipe_line_list;
}	t_mini;

void	ft_echo(t_mini *mini);
int		ft_check_quote(char *line, int q);
void	ft_cd(char **env);
void	ft_execve_cmd(t_mini	*mini);

#endif