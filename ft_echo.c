/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:53:17 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/05 17:01:43 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_n(char *s, int *i, int *n)
{
	int	j;
	int	k;

	j = 0;
	while (1)
	{
		k = 0;
		while (s[j] == ' ')
			j++;
		if (s[j] == '-')
			j++;
		if (s[j] != 'n')
		{
			if (s[j] != ' ' || s[j - 2] != ' ')
				j--;
			break ;
		}
		while (s[j + k] == 'n')
			k++;
		if (s[j + k] == '-')
		{
			j--;
			break ;
		}
		else
			j += k;
		(*n)++;
	}
	(*i) += j;
}

int	ft_check_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i])
		return (0);
	return (1);
}

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

void	ft_print_ent(t_mini *mini, int *i)
{
	char	*s;
	int		j;

	s = ft_get_ent(mini->line + (*i));
	j = 0;
	printf("s == %s\n",s);
	if (ft_strlen(s) == 0)
	{
		printf("$");
		return ;
	}
	while (mini->env[j])
	{
		if (!(ft_strncmp(s, mini->env[j], ft_strlen(s) - 1)))
		{
			if (mini->env[j][ft_strlen(s)] == '=')
			{
				printf("%s", mini->env[j] + ft_strlen(s) + 1);
				(*i) += ft_strlen(s);
				return ;
			}
		}
		j++;
	}
	(*i) += ft_strlen(s);
}

void	ft_echo(t_mini	*mini)
{
	int		i;
	int		n;
	char	*line;

	i = 5;
	n = 0;
	line = mini->line;
	ft_check_n(line + i, &i, &n);
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == 39)
		{
			if (ft_check_quote(line + i, 39))
				printf("%c", line[i]);
			i++;
			while (line[i] && line[i] != 39)
			{
				if (ft_check_quote(line + i, 39) && line[i] == ' ')
					break ;
				if (line[i] != 39)
					printf("%c", line[i]);
				i++;
			}
			i++;
		}
		else if (line[i] == 34)
		{
			if (ft_check_quote(line + i, 34))
				printf("%c", line[i]);
			i++;
			while (line[i] && line[i] != 34)
			{
				if (ft_check_quote(line + i, 34) && line[i] == ' ')
					break ;
				if (line[i] != 34)
					printf("%c", line[i]);
				i++;
			}
			i++;
		}
		else
		{
			while (line[i] && line[i] != ' ' && line[i] != 34 && line[i] != 39)
			{
				if (line[i] == '$')
					ft_print_ent(mini, &i);
				else
					printf("%c", line[i]);
				i++;
			}
		}
		if (line[i] && line[i] != 34 && line[i] != 39)
			printf(" ");
	}
	if (n == 0)
		printf("\n");
}

// void	ft_echo(char **list)
// {
// 	int	i;
// 	int	j;
// 	int	c;

// 	i = 1;
// 	c = 0;
// 	while (list[i])
// 	{
// 		j = 0;
		// if (ft_check_n(list[i]) && c == 0)
		// 	c++;
// 		else
// 		{
// 			while (list[i][j])
// 			{
// 				write(1, &list[i][j], 1);
// 				j++;
// 			}
// 			if (list[i + 1])
// 				write(1, " ", 1);
// 		}
// 		i++;
// 	}
// 	if (c != 1)
// 		write(1, "\n", 1);
// }