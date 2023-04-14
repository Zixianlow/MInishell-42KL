/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:58:58 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/04/14 17:57:41 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	**move_pwd(t_mini *mini, char *str, char *str2)
{
	int		i;
	char	**temp;

	i = 0;
	while (mini->env[i])
		i++;
	temp = malloc(sizeof(char *) * i + 2);
	i = 0;
	while (mini->env[i + 1])
	{
		temp[i] = ft_strdup(mini->env[i]);
		i++;
	}
	temp[i++] = ft_strjoin(str, str2);
	temp[i] = NULL;
	return (temp);
}

void	ft_setpwd(t_mini *mini, char *new, char *old, int i)
{
	i = -1;
	while (mini->env[++i])
	{
		if (!ft_strncmp(mini->env[i], "PWD=", 4))
		{
			free (mini->env[i]);
			mini->env[i] = ft_strjoin("PWD=", new);
			break ;
		}
	}
	if (!mini->env[i])
		mini->env = move_pwd(mini, "PWD=", new);
	i = -1;
	while (mini->env[++i])
	{
		if (!ft_strncmp(mini->env[i], "OLDPWD=", 7))
		{
			free (mini->env[i]);
			mini->env[i] = ft_strjoin("OLDPWD=", old);
			break ;
		}
	}
	if (!mini->env[i])
		mini->env = move_pwd(mini, "OLDPWD=", old);
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
			ft_parent_cmd_error(mini, "cd");
		return ;
	}
	ft_setpwd(mini, new, old, i);
	free_cd(&new, &old);
}

void	ft_cd(t_mini *mini, char **env, char **line)
{
	if (!line[2])
		ft_cd_next(mini, env, line);
	else
		ft_parent_cmd_error(mini, "cd");
}
