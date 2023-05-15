/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_in_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:14:12 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/15 20:09:58 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_compared_free_list(char ***list, int *i, int *c)
{
	free((*list)[(*i)]);
	(*i)++;
	if ((*list)[(*i)])
		free((*list)[(*i)++]);
	(*c)++;
}

void	ft_check_and_remove(char ***list, char ***temp, int *j, int *c)
{
	int	i;

	i = 0;
	while ((*list)[i])
	{
		if (!ft_strncmp((*list)[i], "<", 2))
			ft_compared_free_list(list, &i, c);
		else if (!ft_strncmp((*list)[i], ">", 2))
			ft_compared_free_list(list, &i, c);
		else if (!ft_strncmp((*list)[i], ">>", 3))
			ft_compared_free_list(list, &i, c);
		else if (!ft_strncmp((*list)[i], "<<", 3))
			ft_compared_free_list(list, &i, c);
		else
		{
			(*temp)[(*j)++] = ft_strdup((*list)[i]);
			free((*list)[i++]);
		}
	}
}

char	**ft_remove_in_out_from_list(char ***list, int l)
{
	int		i;
	int		j;
	int		c;
	char	**temp;

	c = 0;
	i = 0;
	while ((*list)[i])
		i++;
	if (i == l)
		i++;
	temp = malloc(sizeof(char *) * (i - l + 1));
	j = 0;
	ft_check_and_remove(list, &temp, &j, &c);
	if (j == 0 && c > 0)
		temp[j++] = ft_strdup("cat");
	temp[j] = NULL;
	return (temp);
}
