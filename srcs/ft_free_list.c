/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:45:15 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/15 16:46:30 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_echo_list(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (mini->echo_line[i])
	{
		j = 0;
		while (mini->echo_line[i][j])
		{
			free(mini->echo_line[i][j]);
			j++;
		}
		free(mini->echo_line[i]);
		i++;
	}
	free(mini->echo_line);
}

void	ft_free_pipe_list(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (mini->pipe_line[i])
	{
		j = 0;
		while (mini->pipe_line[i][j])
		{
			free(mini->pipe_line[i][j]);
			j++;
		}
		free(mini->pipe_line[i]);
		i++;
	}
	free(mini->pipe_line);
}
