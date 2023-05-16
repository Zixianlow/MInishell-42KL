/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:05:48 by cping-xu          #+#    #+#             */
/*   Updated: 2023/05/16 15:05:07 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_copy_d(char **line, t_mini *mini)
{
	int		i;
	int		k;
	int		l;

	i = 0;
	k = 0;
	l = 0;
	while (line[i])
	{
		if (check_now_d(line[i], mini))
			k++;
		if (line[i][0] == '$')
			l++;
		i++;
	}
	if (l && !k)
		return (-l);
	return (k);
}

void	ft_update_temp(char **line, char **temp)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (line[++i])
	{
		j = 0;
		k = ft_len_to_eq(line[i]);
		while (temp[j])
		{
			if (!ft_strncmp(temp[j], line[i], k - 1))
			{
				if (temp[j][k] == '=' && line[i][k] == '=')
				{
					free(temp[j]);
					temp[j] = ft_strdup(checkav(line[i]));
				}
			}
			j++;
		}
	}
}

void	ft_copy_env(t_mini *mini, char **temp, int *j)
{
	*j = 0;
	while (mini->env[(*j) + 1])
	{
		temp[(*j)] = ft_strdup(mini->env[(*j)]);
		(*j)++;
	}
}

char	**edit_env(t_mini *mini, char **line)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**temp;

	j = 0;
	i = check_copy_d(line, mini);
	while (mini->env[j])
		j++;
	temp = malloc(sizeof(char *) * (i + j + 1));
	ft_copy_env(mini, temp, &j);
	k = j;
	i = -1;
	while (line[++i])
		if (check_now_d(line[i], mini))
			temp[j++] = ft_strdup(checkav(line[i]));
	temp[j] = ft_strdup(mini->env[k]);
	temp[j + 1] = NULL;
	i = -1;
	while (mini->env[++i])
		free(mini->env[i]);
	free(mini->env);
	ft_update_temp(line, temp);
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
