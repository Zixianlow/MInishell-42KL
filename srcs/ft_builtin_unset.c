/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:21:08 by cping-xu          #+#    #+#             */
/*   Updated: 2023/04/04 17:54:08 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_env(t_mini *mini, int i)
{
	while (mini->env[i + 1])
	{
		free(mini->env[i]);
		mini->env[i] = ft_strdup(mini->env[i + 1]);
		i++;
	}
	free(mini->env[i]);
	mini->env[i] = NULL;
}

void	ft_unset(t_mini *mini, char **line)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (line[i])
	{
		j = 0;
		while (mini->env[j])
		{
			k = ft_strlen(line[i]);
			if (!ft_strncmp(mini->env[j], line[i], k))
			{
				if (mini->env[j][k] == '=')
					move_env(mini, j);
			}
			j++;
		}
		i++;
	}
}
