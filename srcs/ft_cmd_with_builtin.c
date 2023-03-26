/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_with_builtins.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:49:10 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/26 20:50:13 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd(t_mini	*mini, char **line)
{
	char	*str;

	str = line[0];
	if (!str)
		exit(0);
	else if (!ft_strncmp(str, "exit", 5))
		exit(0);
	else if (!ft_strncmp(str, "echo", 5))
	{
		ft_echo(mini, line);
		exit(0);
	}
	else if (!ft_strncmp(str, "cd", 3))
		ft_cd(mini, mini->env, line);
	else if (!ft_strncmp(str, "pwd", 4))
		ft_pwd();
	else if (!ft_strncmp(str, "export", 7))
		printf("cmd = export\n");
	else if (!ft_strncmp(str, "unset", 6))
		printf("cmd = unset\n");
	else if (!ft_strncmp(str, "env", 4))
		ft_print_env(mini->env);
	else
		if (ft_execve_cmd(mini, line))
			exit(0);
	exit(0);
}
