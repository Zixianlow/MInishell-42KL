/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:43:48 by cping-xu          #+#    #+#             */
/*   Updated: 2023/04/04 17:53:44 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_to_slash(char	*line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '/')
		i++;
	return (i);
}

void	ft_dup_rest_of_line(char *line, int i, char **temp, int *len)
{
	while (line[i] && line[i] != '/')
		i++;
	while (line[i])
		(*temp)[(*len)++] = line[i++];
}

int	ft_cd_check_env(char **env, char *line, int i, char **temp)
{
	int	j;
	int	len;
	int	l;

	l = ft_strlen_to_slash(line + i);
	j = -1;
	while (env[++j])
	{
		if (!(ft_strncmp(line + i, env[j], l)) && env[j][l] == '=')
		{
			*temp = malloc(ft_strlen(line) + ft_strlen(env[j] + l) + 1);
			l++;
			i = 0;
			len = 0;
			while (line[i] != '$')
				(*temp)[len++] = line[i++];
			while (env[j][l])
				(*temp)[len++] = env[j][l++];
			ft_dup_rest_of_line(line, i, temp, &len);
			(*temp)[len] = '\0';
			return (1);
		}
	}
	return (0);
}

int	ft_cd_wrong_env(char **env, char *line, int i, char **temp)
{
	int	j;
	int	len;
	int	l;

	l = 4;
	j = -1;
	while (env[++j])
	{
		if (!(ft_strncmp("HOME", env[j], l)) && env[j][l] == '=')
		{
			*temp = malloc(ft_strlen(line) + ft_strlen(env[j] + l) + 1);
			l++;
			i = 0;
			len = 0;
			while (line[i] != '$')
				(*temp)[len++] = line[i++];
			while (env[j][l])
				(*temp)[len++] = env[j][l++];
			ft_dup_rest_of_line(line, i, temp, &len);
			(*temp)[len] = '\0';
			return (1);
		}
	}
	return (0);
}

char	*ft_env_to_line(char *line, char **env, int i)
{
	int		l;
	char	*temp;

	l = ft_strlen_to_slash(line + i);
	if ((line + i)[0] == '$' || l < 1)
		return (line);
	if (ft_cd_check_env(env, line, i, &temp))
	{
		free(line);
		return (temp);
	}
	if (ft_cd_wrong_env(env, line, i, &temp))
	{
		free(line);
		return (temp);
	}
	return (line);
}
