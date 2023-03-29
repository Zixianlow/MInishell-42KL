/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:45:45 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/29 19:48:04 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_heredoc(t_mini *mini)
{
	mini->heredoc = ft_strdup("heredoc > ");
	mini->here_line = readline(mini->heredoc);
}

void	ft_here_fd(t_mini *mini, int *f, char *line)
{
	int	l;
	int	fd;

	mini->here_fd[*f] = malloc(2);
	pipe(mini->here_fd[*f]);
	while (1)
	{
		print_heredoc(mini);
		l = ft_strlen(line) + 1;
		if (!ft_strncmp(mini->here_line, line, l))
			break ;
		fd = mini->here_fd[*f][1];
		write(fd, mini->here_line, ft_strlen(mini->here_line));
		write(fd, "\n", 1);
	}
	(*f)++;
	mini->here_count = *f;
}

void	ft_get_here_pipe_fd(t_mini *mini, int l)
{
	int	i;
	int	j;
	int	f;

	i = -1;
	f = 0;
	mini->here_fd = malloc((sizeof(int *)) * l);
	while (mini->pipe_line_list[++i])
	{
		j = -1;
		while (mini->pipe_line_list[i][++j] && mini->pipe_line_list[i][j + 1])
		{
			if (!ft_strncmp(mini->pipe_line_list[i][j], "<<", 3))
				ft_here_fd(mini, &f, mini->pipe_line_list[i][j + 1]);
		}
	}
}

void	ft_get_here_pipe(t_mini *mini)
{
	int	i;
	int	j;
	int	l;

	i = -1;
	l = 0;
	mini->here_count = 0;
	mini->here_id = 0;
	while (mini->pipe_line_list[++i])
	{
		j = -1;
		while (mini->pipe_line_list[i][++j])
		{
			if (!ft_strncmp(mini->pipe_line_list[i][j], "<<", 3))
				l++;
		}
	}
	if (l == 0)
		return ;
	else
		ft_get_here_pipe_fd(mini, l);
}

void	ft_create_pipes_fd(t_mini *mini)
{
	int	i;
	int	p;

	p = 0;
	while (mini->pipe_line_list[p])
		p++;
	if (!p)
		return ;
	else
		mini->fd = malloc(sizeof(int *) * (p - 1));
	i = 0;
	while (i < p)
	{
		mini->fd[i] = malloc(sizeof(int) * 2);
		pipe(mini->fd[i]);
		i++;
	}
	mini->pipe_count = p;
}
