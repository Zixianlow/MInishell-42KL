/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:18:00 by cping-xu          #+#    #+#             */
/*   Updated: 2023/05/15 16:39:06 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_treat_double_quote(char *line, char **temp, int *i, int *j)
{
	(*i)++;
	while (line[(*i)] && line[(*i)] != 39)
	{
		if (ft_check_quote(line + (*i), 39))
			break ;
		(*temp)[(*j)++] = line[(*i)++];
	}
	(*i)++;
}

void	ft_treat_single_quote(char *line, char **temp, int *i, int *j)
{
	(*i)++;
	while (line[(*i)] && line[(*i)] != 34)
	{
		if (ft_check_quote(line + (*i), 34))
			break ;
		(*temp)[(*j)++] = line[(*i)++];
	}
	(*i)++;
}

char	*ft_treat_line(char *line)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (line[i])
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == 39)
			ft_treat_double_quote(line, &temp, &i, &j);
		else if (line[i] == 34)
			ft_treat_single_quote(line, &temp, &i, &j);
		else
			temp[j++] = line[i++];
	}
	temp[j] = '\0';
	free(line);
	return (temp);
}

void	ft_treat_pipe_line(char ***pipe_line, char **env, t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	(void)env;
	while (pipe_line[i])
	{
		j = 0;
		while (pipe_line[i][j])
		{
			pipe_line[i][j] = charcmp(pipe_line[i][j], mini->err, NULL);
			mini->echo_line[i][j] = ft_strdup(pipe_line[i][j]);
			pipe_line[i][j] = ft_treat_line(pipe_line[i][j]);
			j++;
		}
		i++;
	}
}

int	ft_calc_list_size(t_mini *mini, int i)
{
	int	l;

	l = 1;
	while (mini->line_list[i] && ft_strncmp(mini->line_list[i], "|", 2))
	{
		l++;
		i++;
	}
	return (l);
}
