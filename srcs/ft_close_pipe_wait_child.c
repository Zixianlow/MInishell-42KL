/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_pipe_wait_child.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:29:27 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/15 21:25:24 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_free_fd(t_mini *mini, int i)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		close(mini->fd[j][0]);
		close(mini->fd[j][1]);
	}
	j = -1;
	if (mini->pipe_count)
	{
		while (++j < mini->pipe_count)
			free(mini->fd[j]);
		free (mini->fd);
	}
}

void	ft_close_pipe_wait_child(t_mini *mini, int i)
{
	int	j;

	j = -1;
	while (++j != mini->here_count)
	{
		close(mini->here_fd[j][0]);
		close(mini->here_fd[j][1]);
	}
	j = -1;
	if (mini->here_count)
	{
		while (++j < mini->here_count)
			free(mini->here_fd[j]);
		free (mini->here_fd);
	}
	ft_close_free_fd(mini, i);
	j = -1;
	while (++j < i)
		waitpid(-1, &mini->err, 0);
}
