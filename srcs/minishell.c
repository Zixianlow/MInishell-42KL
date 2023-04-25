/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:56:11 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/04/25 13:56:04 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_pipe_list(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (mini->pipe_line[i])
	{
		j = 0;
		while (mini->pipe_line[i][j])
		{
			free(mini->pipe_line[i][j]);
			j++;
		}
		free(mini->pipe_line[i]);
		i++;
	}
	free(mini->pipe_line);
}

void	ft_parse_line(t_mini	*mini)
{
	char	*temp;
	int		z;

	temp = ft_line_dup(mini->line);
	ft_change_sp_to_tab(temp);
	mini->line_list = ft_split(temp, 1);
	free(temp);
	ft_get_pipe_line(mini);
	ft_treat_pipe_line(mini->pipe_line, mini->env, mini);
	z = 0;
	while (mini->line_list && mini->line_list[z])
	{
		free (mini->line_list[z]);
		z++;
	}
	free (mini->line_list);
}

char	**ft_strdup_multi(char **env)
{
	char	**temp;
	int		i;

	i = 0;
	while (env[i])
		i++;
	temp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		temp[i] = ft_strdup(env[i]);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

void	runline(t_mini *mini)
{
	int	i;

	i = 0;
	ft_parse_line(mini);
	ft_create_pipes_fd(mini);
	ft_get_here_pipe(mini);
	if (mini->pipe_count == 0 && ft_check_parent_cmd(mini))
		ft_parent_cmd(mini, mini->pipe_line[0]);
	else if (mini->pipe_count > 0 && ft_check_parent_cmd(mini))
		ft_parent_cmd(mini, mini->pipe_line[mini->pipe_count - 1]);
	else
		ft_child_cmd(mini, &i);
	ft_close_pipe_wait_child(mini, i);
	ft_free_pipe_list(mini);
}

int	main(int ac, char **av, char **env)
{
	t_mini	mini;

	(void) ac;
	(void) av;
	mini.env = ft_strdup_multi(env);
	// signal(SIGINT, sig_handler);
	// signal(SIGQUIT, SIG_IGN);
	mini.res = ft_strdup("minishell > ");
	mini.err = 0;
	while (1)
	{
		mini.temp_in = dup(0);
		mini.temp_out = dup(1);
		mini.line = NULL;
		print_default(&mini);
		if (mini.line)
			runline(&mini);
		close(mini.temp_in);
		close(mini.temp_out);
	}
}
