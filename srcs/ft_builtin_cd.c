/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:58:58 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/15 15:17:23 by lzi-xian         ###   ########.fr       */
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

char	*ft_user_input_cwd(char *cwd, char **line, char **env)
{
	char	*temp;
	char	*input;
	char	*hold;
	int		i;

	temp = ft_strjoin(cwd, "/");
	i = 0;
	input = ft_strdup(line[1]);
	while (input[i])
	{
		if (i == 0 && input[i] == '$' && input[i + 1] && input[i + 1] != '/')
		{
			input = ft_env_to_line(input, env, i + 1);
			free (temp);
			temp = ft_strdup("/");
		}
		else if (input[i] == '$' && input[i - 1] != '$' \
			&& input[i + 1] && input[i + 1] != '/')
			input = ft_env_to_line(input, env, i + 1);
		i++;
	}
	hold = ft_strjoin(temp, input);
	free(input);
	free(temp);
	return (hold);
}

void	ft_cd_next(t_mini *mini, char **env, char **line)
{
	char	cwd[PATH_MAX];
	char	*new;
	char	*old;
	int		i;

	getcwd(cwd, sizeof(cwd));
	new = ft_user_input_cwd(cwd, line, env);
	mini->dir_list = ft_split(line[1], '/');
	old = ft_strdup(cwd);
	if (access(new, 0) == 0)
	{
		chdir(new);
		getcwd(cwd, sizeof(cwd));
		free(new);
		new = ft_strdup(cwd);
	}
	else
	{
		free(new);
		if (line[1])
			perror("cd");
		return ;
	}
	i = 0;
	while (env[i])
		if (!ft_strncmp(env[i++], "PWD=", 4))
			break ;
	env[--i] = ft_strjoin("PWD=", new);
	i = 0;
	while (env[i])
		if (!ft_strncmp(env[i++], "OLDPWD=", 7))
			break ;
	env[--i] = ft_strjoin("OLDPWD=", old);
	free(new);
	free(old);
}

void	ft_cd(t_mini *mini, char **env, char **line)
{
	if (!line[2])
		ft_cd_next(mini, env, line);
	else
		perror("cd");
}
