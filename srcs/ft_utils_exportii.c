/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_exportii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:37:03 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/16 15:05:03 by lzi-xian         ###   ########.fr       */
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
		if (check_now(line[i]))
			k++;
		if (line[i][0] == '$')
			l++;
		i++;
	}
	if (l && !k)
		return (-l);
	return (k);
}

int	ft_chk_exist(t_mini *mini, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = ft_len_to_eq(line);
	while (mini->env[i])
	{
		if (!ft_strncmp(mini->env[i], line, j))
			return (0);
		i++;
	}
	return (1);
}

int	check_now_d(char *line, t_mini *mini)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=' && ft_chk_exist(mini, line))
		{
			if (ft_isalpha(line[0]))
				return (1);
		}
		i++;
	}
	return (0);
}
