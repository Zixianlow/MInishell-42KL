/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:57:57 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/15 21:10:12 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_ent(char *s)
{
	int		i;
	int		l;
	char	*ent;

	i = 1;
	l = 1;
	while (s[l] && (ft_isalnum(s[l]) || s[l] == '_'))
		l++;
	ent = malloc(sizeof(char) * l);
	l = 0;
	while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
	{
		ent[l] = s[i];
		l++;
		i++;
	}
	ent[l] = '\0';
	return (ent);
}

int	ft_no_length(char *s)
{
	if (ft_strlen(s) == 0)
	{
		printf("$");
		return (1);
	}
	return (0);
}

void	ft_print_ent(t_mini *mini, char *line, int *i)
{
	char	*s;
	int		j;

	while (line[(*i)] == '$')
		(*i)++;
	(*i)--;
	s = ft_get_ent(line + (*i));
	j = -1;
	if (ft_no_length(s))
		return ;
	while (mini->env[++j])
	{
		if (!(ft_strncmp(s, mini->env[j], ft_strlen(s))))
		{
			if (mini->env[j][ft_strlen(s)] == '=')
			{
				printf("%s", mini->env[j] + ft_strlen(s) + 1);
				(*i) += ft_strlen(s);
				return ;
			}
		}
	}
	(*i) += ft_strlen(s);
}

int	ft_skip_redir(char **list, int *i)
{
	if (!ft_strncmp(list[*i], ">", 2))
	{
		(*i) += 2;
		return (1);
	}
	else if (!ft_strncmp(list[*i], ">", 2))
	{
		(*i) += 2;
		return (1);
	}
	else if (!ft_strncmp(list[*i], ">>", 3))
	{
		(*i) += 2;
		return (1);
	}
	else if (!ft_strncmp(list[*i], "<<", 3))
	{
		(*i) += 2;
		return (1);
	}
	return (0);
}

void	ft_check_n(char **s, int *i, int *c)
{
	int	j;

	j = 0;
	while (s[*i] && s[*i][j])
	{
		while (s[*i][j] == ' ')
			j++;
		if (s[*i][j] == '-')
			j++;
		if (s[*i][j] != 'n')
			return ;
		while (s[*i][j] == 'n')
			j++;
		if (s[*i][j] != '\0')
			return ;
		(*i)++;
		(*c)++;
		j = 0;
	}
}
