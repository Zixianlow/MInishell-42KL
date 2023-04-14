/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:51:15 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/04/14 16:51:53 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_command_path(char	**paths, char *cmd)
{
	int		i;
	char	*temp;
	char	*command;

	i = 0;
	if (access(cmd, 0) == 0)
		return (cmd);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, 0) == 0)
			return (command);
		i++;
		free(command);
	}
	return (NULL);
}

char	*ft_px_get_env_path(char **env)
{
	int	i;

	i = 0;
	while (*env)
	{
		if (!ft_strncmp("PATH=", *env, 5))
			return (*env + 5);
		env++;
	}
	return (NULL);
}

void	ft_execve_cmd(t_mini	*mini, char **line)
{
	int		i;

	i = 0;
	mini->env_path = ft_px_get_env_path(mini->env);
	mini->path_list = ft_split(mini->env_path, ':');
	mini->cmd_path = ft_get_command_path(mini->path_list, line[0]);
	execve(mini->cmd_path, line, mini->env);
	exit (127);
}
