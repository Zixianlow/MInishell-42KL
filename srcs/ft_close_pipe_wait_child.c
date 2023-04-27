/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_pipe_wait_child.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:29:27 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/04/25 18:26:41 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while (++j < i)
	{
		close(mini->fd[j][0]);
		close(mini->fd[j][1]);
	}
	j = -1;
	while (++j < i)
	{
		waitpid(-1, &mini->err, 0);
		if (mini->err != 0)
			perror("cmd");
	}
}
