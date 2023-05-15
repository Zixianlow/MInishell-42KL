/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:19:53 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/15 16:21:51 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strtrim2(char *s1, char sep1, char sep2)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = 0;
	while (s1[++i])
	{
		if (s1[i] == sep1)
		{
			i++;
			if (s1[i] == sep2)
			{
				j = i - 2;
				break ;
			}
		}
	}
	s = malloc(sizeof(char) * j + 1);
	i = -1;
	while (++i <= j)
		s[i] = s1[i];
	s[i] = '\0';
	return (s);
}

char	*charcmp(char *pipe, int input)
{
	int		i;
	char	*temp;
	char	*temp1;
	char	*temp2;
	char	*new;

	i = -1;
	new = ft_itoa(input / 256);
	while (pipe[++i])
	{
		if (pipe[i] == '$' && pipe[i + 1] == '?')
		{
			temp1 = ft_strdup(pipe);
			temp1 = ft_strtrim2(temp1, '$', '?');
			temp2 = ft_strjoin(temp1, new);
			free(temp1);
			temp = ft_strdup(&pipe[i + 2]);
			free (pipe);
			pipe = ft_strjoin(temp2, temp);
			free(temp);
			free(temp2);
			i = -1;
		}
	}
	free(new);
	return (pipe);
}

void	ft_parent_cmd_error(t_mini *mini, char *s)
{
	mini->err = 256;
	perror(s);
}
