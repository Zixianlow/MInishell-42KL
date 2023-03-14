/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:58:58 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/14 20:47:29 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_trim(char **str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while ((*str)[i])
		i++;
	i--;
	while (i >= 0)
	{
		if ((*str)[i] != '/')
			i--;
		else
			break ;
	}
	temp = malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		temp[j] = (*str)[j];
		j++;
	}
	if (i == 0)
	{
		temp[j] = (*str)[j];
		j++;
	}
	temp[j] = '\0';
	free (*str);
	return (temp);
}

int	ft_strlen_to_slash(char	*line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '/')
		i++;
	return (i);
}

char	*ft_env_to_line(char *line, char **env, int i)
{
	int		j;
	int		k;
	int		l;
	int		len;
	char	*temp;

	j = 0;
	while (env[j])
	{
		l = ft_strlen_to_slash(line + i);
		if (!(ft_strncmp(line + i, env[j], l)))
		{
			if (env[j][l] == '=')
			{
				len = ft_strlen(line) + ft_strlen(env[j] + l);
				temp = malloc(len + 1);
				l++;
				i = 0;
				len = 0;
				while (line[i] != '$')
					temp[len++] = line[i++];
				i += l;
				while (env[j][l])
					temp[len++] = env[j][l++];
				while (line[i])
					temp[len++] = line[i++];
				temp[len] = '\0';
				free(line);
				return (temp);
			}
		}
		j++;
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
		{
			input = ft_env_to_line(input, env, i + 1);
		}
		i++;
	}
	hold = ft_strjoin(temp, input);
	free(input);
	free(temp);
	return (hold);
}

char	*ft_make_user_input_cwd(char **cwd, char *line)
{
	char	*temp;
	char	*hold;

	temp = ft_strjoin(*cwd, "/");
	free(*cwd);
	hold = ft_strjoin(temp, line);
	free(temp);

	return (hold);
}

void	ft_cd_next(t_mini *mini, char **env, char **line)
{
	char	cwd[PATH_MAX];
	char	*new_cwd;
	char	*new;
	char	*old;
	int		i;

	getcwd(cwd, sizeof(cwd));
	new_cwd = ft_user_input_cwd(cwd, line, env);
	mini->dir_list = ft_split(line[1], '/');
	old = ft_strdup(cwd);
	i = 0;
	if (access(new_cwd, 0) == 0)
	{
		if (line[1][i] == '$')
		{
			i++;
		}
		free(new_cwd);
		new_cwd = ft_strdup(cwd);
		while (mini->dir_list[i])
		{
			if (!ft_strncmp(mini->dir_list[i], "..", 3))
				new_cwd = ft_trim(&new_cwd);
			else if (ft_strncmp(mini->dir_list[i], ".", 2))
				new_cwd = ft_make_user_input_cwd(&new_cwd, mini->dir_list[i]);
			i++;
		}
		new = new_cwd;
	}
	else
	{
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
	chdir(new_cwd);
}

void	ft_cd(t_mini *mini, char **env, char **line)
{
	if (!line[2])
		ft_cd_next(mini, env, line);
	else
		perror("cd");
}
