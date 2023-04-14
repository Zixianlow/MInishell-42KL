/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:26:49 by cping-xu          #+#    #+#             */
/*   Updated: 2023/04/14 17:58:34 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handle_in(char ***list, int *i, int *l)
{
	int	fd;

	if (!ft_strncmp((*list)[(*i)], "<", 2))
	{
		(*l)++;
		if ((*list)[(*i) + 1])
		{
			(*l)++;
			fd = open((*list)[(*i) + 1], O_RDONLY);
			if (fd == -1)
			{
				perror("Infile");
				exit(1);
			}
			dup2(fd, 0);
			close(fd);
		}
	}
}

void	ft_handle_out(char ***list, int *i, int *l)
{
	int	fd;

	if (!ft_strncmp((*list)[(*i)], ">", 2))
	{
		(*l)++;
		if ((*list)[(*i) + 1])
		{
			(*l)++;
			fd = open((*list)[(*i) + 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
			dup2(fd, 1);
			close(fd);
		}
	}
}

void	ft_handle_in_double(char ***list, int *i, int *l, t_mini *mini)
{
	int	fd;

	if (!ft_strncmp((*list)[(*i)], "<<", 3))
	{
		(*l)++;
		if ((*list)[(*i) + 1])
		{
			dup2(mini->here_fd[mini->here_id][0], 0);
			close(mini->here_fd[mini->here_id][0]);
			close(mini->here_fd[mini->here_id][1]);
			mini->here_id++;
		}
		else
		{
			perror("parse");
			exit(1);
		}
	}
}

void	ft_handle_out_double(char ***list, int *i, int *l)
{
	int	fd;

	if (!ft_strncmp((*list)[(*i)], ">>", 3))
	{
		(*l)++;
		if ((*list)[(*i) + 1])
		{
			(*l)++;
			fd = open((*list)[(*i) + 1], O_APPEND | O_CREAT | O_RDWR, 0644);
			if (fd == -1)
			{
				perror("Outfile");
				exit(1);
			}
			dup2(fd, 1);
			close(fd);
		}
	}
}

void	ft_handle_in_out_file(t_mini *mini, int n)
{
	int		i;
	int		l;
	char	***list;

	i = 0;
	l = 0;
	list = &mini->pipe_line[n];
	while ((*list)[i])
	{
		ft_handle_in(list, &i, &l);
		ft_handle_out(list, &i, &l);
		ft_handle_in_double(list, &i, &l, mini);
		ft_handle_out_double(list, &i, &l);
		i++;
	}
	*list = ft_remove_in_out_from_list(list, l);
}
