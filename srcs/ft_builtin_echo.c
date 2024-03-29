/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:53:17 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/15 21:01:42 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo_single_quote(char *s, int *j)
{
	if (ft_check_quote(s + (*j), 39))
		printf("%c", s[*j]);
	(*j)++;
	while (s[*j] && s[*j] != 39)
	{
		if (ft_check_quote(s + (*j), 39))
			break ;
		printf("%c", s[*j]);
		(*j)++;
	}
	(*j)++;
}

void	ft_echo_double_quote(t_mini *mini, char *s, int *j)
{
	if (ft_check_quote(s + (*j), 34))
		printf("%c", s[*j]);
	(*j)++;
	while (s[*j] && s[*j] != 34)
	{
		if (ft_check_quote(s + (*j), 34))
			break ;
		if (s[*j] == '$')
			ft_print_ent(mini, s, j);
		else
			printf("%c", s[*j]);
		(*j)++;
	}
	(*j)++;
}

void	ft_echo_normal(t_mini *mini, char *s, int *j)
{
	while (s[*j] && s[*j] != 34 && s[*j] != 39)
	{
		if (s[*j] == '$')
			ft_print_ent(mini, s, j);
		else
			printf("%c", s[*j]);
		(*j)++;
	}
}

void	ft_echo_loop(t_mini *mini, char **list, int i)
{
	int	j;

	j = 0;
	while (list[i][j])
	{
		if (list[i][j] == 39)
			ft_echo_single_quote(list[i], &j);
		else if (list[i][j] == 34)
			ft_echo_double_quote(mini, list[i], &j);
		else
			ft_echo_normal(mini, list[i], &j);
	}
}

void	ft_echo(t_mini *mini, char **list)
{
	int	i;
	int	c;

	i = 1;
	c = 0;
	ft_check_n(list, &i, &c);
	while (list[i])
	{
		if (ft_skip_redir(list, &i))
			continue ;
		ft_echo_loop(mini, list, i);
		i++;
		if (list[i])
			printf(" ");
	}
	if (c == 0)
		printf("\n");
}
