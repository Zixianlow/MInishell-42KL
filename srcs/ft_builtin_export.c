/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:05:48 by cping-xu          #+#    #+#             */
/*   Updated: 2023/04/04 17:55:34 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_mini *mini)
{
	int	i;
	int	j;
	int	k;
	int	ac;

	ac = 0;
	while (mini->env[ac])
		ac++;
	i = 0;
	if (ac > 1)
	{
		while (++i < ac)
		{
			j = 0;
			while (++j < ac - 1)
			{
				k = j + 1;
				if (ft_strcmp(mini->env[j], mini->env[k]) > 0)
					ft_swap(&mini->env[j--], &mini->env[k]);
			}
		}
	}
	i = 0;
	while (++i < ac)
		printf("%s\n", mini->env[i]);
}

int	check_copy(char **line)
{
	int		i;
	int		k;
	int		l;

	i = 0;
	k = 0;
	l = 0;
	while (line[i])
	{
		if (checkav(line[i]))
			k++;
		if (line[i][0] == '$')
			l++;
		i++;
	}
	if (l && !k)
		return (-l);
	return (k);
}

int	check_now(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
		{
			if (ft_isalpha(line[0]))
				return (1);
		}
		i++;
	}
	return (0);
}

char	**edit_env(t_mini *mini, char **line)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	j = 0;
	i = check_copy(line);
	while (mini->env[j])
		j++;
	temp = malloc(sizeof(char *) * (i + j + 1));
	j = 0;
	while (mini->env[j + 1])
	{
		temp[j] = ft_strdup(mini->env[j]);
		j++;
	}
	k = j;
	i = -1;
	while (line[++i])
		if (check_now(line[i]))
			temp[j++] = ft_strdup(checkav(line[i]));
	temp[j] = ft_strdup(mini->env[k]);
	temp[j + 1] = NULL;
	return (temp);
}

void	ft_export(t_mini *mini, char **line)
{
	if (!line[1])
		print_export(mini);
	else
	{
		if (check_copy(line) > 0)
		{
			mini->env = edit_env(mini, line);
			return ;
		}
		else if (check_copy(line) == 0)
			return ;
		else
			print_export(mini);
	}
	return ;
}
