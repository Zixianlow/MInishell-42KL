/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:46:45 by cping-xu          #+#    #+#             */
/*   Updated: 2023/04/04 18:47:14 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_pipe_line2(t_mini *mini)
{
	int	i;
	int	l;
	int	k;

	i = 0;
	l = 0;
	k = 0;
	mini->pipe_line[l] = malloc(sizeof(char *) * ft_calc_list_size(mini, i));
	while (mini->line_list[i] && ft_strncmp(mini->line_list[i], "|", 2))
	{
		mini->pipe_line[l][k] = ft_strdup(mini->line_list[i]);
		k++;
		i++;
		if (mini->line_list[i] && !ft_strncmp(mini->line_list[i], "|", 2))
		{
			mini->pipe_line[l][k] = NULL;
			l++;
			i++;
			mini->pipe_line[l] = malloc(sizeof(char *) * \
				ft_calc_list_size(mini, i));
			k = 0;
		}
	}
	mini->pipe_line[l][k] = NULL;
}

void	ft_get_pipe_line(t_mini *mini)
{
	int	i;
	int	l;
	int	k;

	i = 0;
	l = 1;
	while (mini->line_list[i])
	{
		if (!ft_strncmp(mini->line_list[i], "|", 2))
			l++;
		i++;
	}
	if (i > 0)
		l++;
	mini->pipe_line = malloc(sizeof(char **) * l);
	mini->pipe_line[l - 1] = NULL;
	ft_get_pipe_line2(mini);
}
