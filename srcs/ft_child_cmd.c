/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:38:21 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/04/18 15:38:36 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ft_chk_in(t_mini *mini, int i)
{
	int	j;

	j = 0;
	while (mini->pipe_line[(i)][j])
	{
		if (!ft_strncmp(mini->pipe_line[(i)][j], "<", 2))
			if (mini->pipe_line[(i)][j + 1])
				return (1);
		if (!ft_strncmp(mini->pipe_line[(i)][j], "<<", 3))
			if (mini->pipe_line[(i)][j + 1])
				return (1);
		j++;
	}
	return (0);
}

int	ft_chk_out(t_mini *mini, int i)
{
	int	j;

	j = 0;
	while (mini->pipe_line[(i)][j])
	{
		if (!ft_strncmp(mini->pipe_line[(i)][j], ">", 2))
			if (mini->pipe_line[(i)][j + 1])
				return (1);
		if (!ft_strncmp(mini->pipe_line[(i)][j], ">>", 3))
			if (mini->pipe_line[(i)][j + 1])
				return (1);
		j++;
	}
	return (0);
}

void	ft_set_process_pipe(t_mini *mini, int *i)
{
	if ((*i) > 0 && !ft_chk_in(mini, *i))
	{
		close(mini->fd[(*i) - 1][1]);
		close(mini->temp_in);
		mini->temp_in = mini->fd[(*i) - 1][0];
	}
	if (mini->pipe_line[(*i) + 1] && !ft_chk_out(mini, *i))
	{
		close(mini->temp_out);
		mini->temp_out = mini->fd[(*i)][1];
	}
	else
	{
		close(mini->temp_out);
		mini->temp_out = dup(1);
	}
}

void	ft_child_cmd(t_mini *mini, int *i)
{
	int	m;

	while (mini->pipe_line[(*i)])
	{
		mini->pid2 = fork();
		if (mini->pid2 == 0)
		{
			ft_set_process_pipe(mini, i);
			ft_handle_in_out_file(mini, (*i));
			m = -1;
			while (++m < mini->here_count)
				close(mini->here_fd[m][1]);
			dup2(mini->temp_in, 0);
			dup2(mini->temp_out, 1);
			close(mini->temp_in);
			close(mini->temp_out);
			ft_cmd(mini, mini->pipe_line[(*i)]);
		}
		(*i)++;
	}
}
