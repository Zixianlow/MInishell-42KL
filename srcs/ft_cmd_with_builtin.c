/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_with_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:49:10 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/15 16:11:11 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd(t_mini	*mini, char **line, char **echo)
{
	if (!line[0])
		exit(0);
	else if (!ft_strncmp(echo[0], "echo", 5))
	{
		ft_echo(mini, echo);
		exit(0);
	}
	else if (!ft_strncmp(line[0], "pwd", 4))
		ft_pwd(line);
	else if (!ft_strncmp(line[0], "env", 4))
		ft_print_env(mini->env);
	else
		ft_execve_cmd(mini, line);
	exit(0);
}
