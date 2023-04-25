/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:41:42 by cping-xu          #+#    #+#             */
/*   Updated: 2023/04/20 16:55:45 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quote(char *line, int q)
{
	int	i;

	i = 1;
	while (line[i] && line[i] != q)
		i++;
	if (line[i] == q)
		return (0);
	return (1);
}

void	free_cd(char **new, char **old)
{
	free(*new);
	free(*old);
}

void	ft_set_sp_to_tab(int *i, char *s, char ch)
{
	(*i)++;
	while (s[(*i)] && s[(*i)] != ch)
	{
		if (ft_check_quote(s + (*i), ch) && s[(*i)] == ' ')
			break ;
		(*i)++;
	}
	if (s[(*i)] == ' ')
		s[(*i)] = 1;
}

void	ft_change_sp_to_tab(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 39)
			ft_set_sp_to_tab(&i, s, 39);
		else if (s[i] == 34)
			ft_set_sp_to_tab(&i, s, 34);
		else if (s[i] == ' ')
			s[i] = 1;
		i++;
	}
}

void	print_default(t_mini *mini)
{
	mini->line = readline(mini->res);
	if (!mini->line)
		exit(0);
	if (mini->line)
		add_history(mini->line);
}
