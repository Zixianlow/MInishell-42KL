/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:55:53 by cping-xu          #+#    #+#             */
/*   Updated: 2023/05/16 14:57:09 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_len_to_eq(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			break ;
		i++;
	}
	return (i);
}

char	*checkav(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
		{
			if (ft_isalpha(line[0]))
				return (line);
		}
		i++;
	}
	return (NULL);
}
