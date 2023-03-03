/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:56:11 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/02 18:50:42 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **list)
{
	int	i;
	int	j;

	i = 1;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			write(1, &list[i][j], 1);
			j++;
		}
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_env(char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			write(1, &env[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_cmd(t_mini	*mini)
{
	char	*str;

	str = mini->line_list[0];
	if (!str)
		printf("cmd = NULL\n");
	else if (!ft_strncmp(str, "exit", 5))
		exit(0);
	else if (!ft_strncmp(str, "echo", 5))
		ft_echo(mini->line_list);
	else if (!ft_strncmp(str, "cd", 3))
		printf("cmd = cd\n");
	else if (!ft_strncmp(str, "pwd", 4))
		printf("cmd = pwd\n");
	else if (!ft_strncmp(str, "export", 7))
		printf("cmd = export\n");
	else if (!ft_strncmp(str, "unset", 6))
		printf("cmd = unset\n");
	else if (!ft_strncmp(str, "env", 4))
		ft_print_env(mini->env);
}

void	ft_parse_line(t_mini	*mini)
{
	mini->line_list = ft_split(mini->line, ' ');
}

void	print_default(t_mini	*mini)
{
	char	*temp;
	char	*half;
	char	*end;

	temp = NULL;
	temp = ft_strjoin("\e[0;93m", getenv("USER"));
	//make green user
	if (!temp)
		temp = ft_strjoin("\e[0;93m", getenv("user"));
	half = ft_strjoin("\e[0;92m", "@minishell$ ");
	end = ft_strjoin(half, "\e[0m");
	free(half);
	// make minishell yellow and wont keep colouring
	mini->res = ft_strjoin(temp, end);
	free(temp);
	free(end);
	mini->line = readline(mini->res);
	if (mini->line)
		add_history(mini->line);
}

int	main(int ac, char **av, char **env)
{
	t_mini	mini;

	(void) ac;
	(void) av;
	mini.env = env;
	while (1)
	{
		mini.line = NULL;
		print_default(&mini);
		if (mini.line)
		{
			ft_parse_line(&mini);
			ft_cmd(&mini);
		}
	}
}

