/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:53:17 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/04/04 17:41:58 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (s[*i][j] == '-')
			return ;
		(*i)++;
		(*c)++;
		j = 0;
	}
}

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

void	ft_echo(t_mini *mini, char **list)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	c = 0;
	ft_check_n(list, &i, &c);
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			if (list[i][j] == '$')
				ft_print_ent(mini, list[i], &j);
			else
				printf("%c", list[i][j]);
			j++;
		}
		if (list[i + 1])
			printf(" ");
		i++;
	}
	if (c == 0)
		printf("\n");
}
