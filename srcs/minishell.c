/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:56:11 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/30 17:11:19 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_change_sp_to_tab(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 39)
		{
			i++;
			while (s[i] && s[i] != 39)
			{
				if (ft_check_quote(s + i, 39) && s[i] == ' ')
					break ;
				i++;
			}
			if (s[i] == ' ')
				s[i] = '\t';
		}
		else if (s[i] == 34)
		{
			i++;
			while (s[i] && s[i] != 34)
			{
				if (ft_check_quote(s + i, 34) && s[i] == ' ')
					break ;
				i++;
			}
			if (s[i] == ' ')
				s[i] = '\t';
		}
		else if (s[i] == ' ')
			s[i] = '\t';
		i++;
	}
}

char	*ft_treat_line(char *line)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (line[i])
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == 39)
		{
			i++;
			while (line[i] && line[i] != 39)
			{
				if (ft_check_quote(line + i, 39))
					break ;
				temp[j++] = line[i++];
			}
			i++;
		}
		else if (line[i] == 34)
		{
			i++;
			while (line[i] && line[i] != 34)
			{
				if (ft_check_quote(line + i, 34))
					break ;
				temp[j++] = line[i++];
			}
			i++;
		}
		else
			temp[j++] = line[i++];
	}
	temp[j] = '\0';
	free(line);
	return (temp);
}

void	ft_treat_pipe_line_list(char ***pipe_line_list, char **env)
{
	int	i;
	int	j;

	i = 0;
	(void)env;
	while (pipe_line_list[i])
	{
		j = 0;
		while (pipe_line_list[i][j])
		{
			pipe_line_list[i][j] = ft_treat_line(pipe_line_list[i][j]);
			j++;
		}
		i++;
	}
}

char	*ft_line_dup(char *s)
{
	char	*dest;
	int		i;
	int		j;
	int		c;

	i = 0;
	j = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '|' || s[i] == '<' || s[i] == '>')
			c += 2;
		i++;
	}
	dest = (char *) malloc (sizeof(char) * (i + c + 1));
	i = 0;
	if (!dest)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == 39)
		{
			dest[j++] = s[i++];
			while (s[i] && s[i] != 39)
			{
				if (ft_check_quote(s + i, 39))
					break ;
				dest[j++] = s[i++];
			}
		}
		else if (s[i] == 34)
		{
			dest[j++] = s[i++];
			while (s[i] && s[i] != 34)
			{
				if (ft_check_quote(s + i, 34))
					break ;
				dest[j++] = s[i++];
			}
		}
		if (s[i] == '|')
		{
			dest[j++] = ' ';
			dest[j++] = '|';
			dest[j++] = ' ';
			i++;
		}
		else if (s[i] == '<' && s[i + 1] == '<')
		{
			dest[j++] = ' ';
			dest[j++] = '<';
			dest[j++] = '<';
			dest[j++] = ' ';
			i += 2;
		}
		else if (s[i] == '>' && s[i + 1] == '>')
		{
			dest[j++] = ' ';
			dest[j++] = '>';
			dest[j++] = '>';
			dest[j++] = ' ';
			i += 2;
		}
		else if (s[i] == '<')
		{
			dest[j++] = ' ';
			dest[j++] = '<';
			dest[j++] = ' ';
			i++;
		}
		else if (s[i] == '>')
		{
			dest[j++] = ' ';
			dest[j++] = '>';
			dest[j++] = ' ';
			i++;
		}
		else
			dest[j++] = s[i++];
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_calc_list_size(t_mini *mini, int i)
{
	int	l;

	l = 1;
	while (mini->line_list[i] && ft_strncmp(mini->line_list[i], "|", 2))
	{
		l++;
		i++;
	}
	return (l);
}

void	ft_get_pipe_line_list(t_mini *mini)
{
	int	i;
	int	l;
	int	k;

	i = 0;
	l = 1;
	while (mini->line_list[i])
	{
		if (!ft_strncmp(mini->line_list[i], "|", 2))
			l++;
		i++;
	}
	if (i > 0)
		l++;
	mini->pipe_line_list = malloc(sizeof(char **) * l);
	mini->pipe_line_list[l - 1] = NULL;
	i = 0;
	l = 0;
	k = 0;
	mini->pipe_line_list[l] = malloc(sizeof(char *) * ft_calc_list_size(mini, i));
	while (mini->line_list[i] && ft_strncmp(mini->line_list[i], "|", 2))
	{
		mini->pipe_line_list[l][k] = ft_strdup(mini->line_list[i]);
		k++;
		i++;
		if (mini->line_list[i] && !ft_strncmp(mini->line_list[i], "|", 2))
		{
			mini->pipe_line_list[l][k] = NULL;
			l++;
			i++;
			mini->pipe_line_list[l] = malloc(sizeof(char *) * ft_calc_list_size(mini, i));
			k = 0;
		}
	}
	mini->pipe_line_list[l][k] = NULL;
}

void	ft_parse_line(t_mini	*mini)
{
	char	*temp;

	temp = ft_line_dup(mini->line);
	ft_change_sp_to_tab(temp);
	mini->line_list = ft_split(temp, '\t');
	free(temp);
	ft_get_pipe_line_list(mini);
	ft_treat_pipe_line_list(mini->pipe_line_list, mini->env);
}

void	print_default(t_mini	*mini)
{
	mini->res = ft_strdup("minishell > ");
	mini->line = readline(mini->res);
	if (mini->line)
		add_history(mini->line);
}

char	**ft_remove_in_out_from_list(char ***list, int l)
{
	int		i;
	int		j;
	int		c;
	char	**temp;

	c = 0;
	i = 0;
	while ((*list)[i])
		i++;
	if (i == l)
		i++;
	temp = malloc(sizeof(char *) * (i - l + 1));
	i = 0;
	j = 0;
	while ((*list)[i])
	{
		if (!ft_strncmp((*list)[i], "<", 2))
		{
			free((*list)[i]);
			i++;
			if ((*list)[i] && ft_strncmp((*list)[i], ">", 2))
				free((*list)[i++]);
			c++;
		}
		else if (!ft_strncmp((*list)[i], ">", 2))
		{
			free((*list)[i]);
			i++;
			if ((*list)[i] && ft_strncmp((*list)[i], "<", 2))
				free((*list)[i++]);
			c++;
		}
		else if (!ft_strncmp((*list)[i], ">>", 3))
		{
			free((*list)[i]);
			i++;
			if ((*list)[i])
				free((*list)[i++]);
			c++;
		}
		else if (!ft_strncmp((*list)[i], "<<", 3))
		{
			free((*list)[i]);
			i++;
			if ((*list)[i])
				free((*list)[i++]);
			c++;
		}
		else
		{
			temp[j++] = ft_strdup((*list)[i]);
			free((*list)[i++]);
		}
	}
	if (j == 0 && c > 0)
		temp[j++] = ft_strdup("cat");
	temp[j] = NULL;
	return (temp);
}

void	ft_handle_in_out_file(t_mini *mini, int n)
{
	int		i;
	int		l;
	int		fd;
	char	***list;

	i = 0;
	l = 0;
	list = &mini->pipe_line_list[n];
	while ((*list)[i])
	{
		if (!ft_strncmp((*list)[i], "<", 2))
		{
			l++;
			if ((*list)[i + 1])
			{
				l++;
				fd = open((*list)[i + 1], O_RDONLY);
				if (fd == -1)
				{
					perror("Infile");
					exit(0);
				}
				dup2(fd, 0);
				close(fd);
			}
		}
		else if (!ft_strncmp((*list)[i], ">", 2))
		{
			l++;
			if ((*list)[i + 1])
			{
				l++;
				fd = open((*list)[i + 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
				dup2(fd, 1);
				close(fd);
			}
		}
		else if (!ft_strncmp((*list)[i], ">>", 3))
		{
			l++;
			if ((*list)[i + 1])
			{
				l++;
				fd = open((*list)[i + 1], O_APPEND | O_CREAT | O_RDWR, 0644);
				if (fd == -1)
					perror("Outfile");
				dup2(fd, 1);
				close(fd);
			}
		}
		if (!ft_strncmp((*list)[i], "<<", 3))
		{
			l++;
			if ((*list)[i + 1])
			{
				dup2(mini->here_fd[mini->here_id][0], 0);
				close(mini->here_fd[mini->here_id][0]);
				close(mini->here_fd[mini->here_id][1]);
				mini->here_id++;
			}
			else
				perror("parse");
		}
		i++;
	}
	*list = ft_remove_in_out_from_list(list, l);
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

int	ft_check_parent_cmd(t_mini *mini)
{
	int		i;
	char	**list;

	i = 0;
	list = mini->pipe_line_list[mini->pipe_count - 1];
	while (list[i])
	{
		if (!ft_strncmp(list[i], "exit", 5))
			return (1);
		else if (!ft_strncmp(list[i], "cd", 3))
			return (1);
		else if (!ft_strncmp(list[i], "export", 7))
			return (1);
		else if (!ft_strncmp(list[i], "unset", 6))
			return (1);
		i++;
	}
	return (0);
}

void	ft_parent_cmd(t_mini	*mini, char **line)
{
	char	*str;

	str = line[0];
	if (!str)
		exit(0);
	else if (!ft_strncmp(str, "exit", 5))
		exit(0);
	else if (!ft_strncmp(str, "cd", 3))
		ft_cd(mini, mini->env, line);
	else if (!ft_strncmp(str, "export", 7))
		printf("cmd = export\n");
	else if (!ft_strncmp(str, "unset", 6))
		printf("cmd = unset\n");
}

void	ft_child_cmd(t_mini *mini, int i)
{
	while (mini->pipe_line_list[i])
	{
		mini->pid2 = fork();
		if (mini->pid2 == 0)
		{
			if (i > 0)
			{
				close(mini->fd[i - 1][1]);
				dup2(mini->fd[i - 1][0], 0);
			}
			if (mini->pipe_line_list[i + 1])
				dup2(mini->fd[i][1], 1);
			else
				dup2(1, 1);
			ft_handle_in_out_file(mini, i);
			ft_cmd(mini, mini->pipe_line_list[i]);
		}
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_mini	mini;
	int		i;

	(void) ac;
	(void) av;
	mini.env = ft_strdup_multi(env);
	// signal(SIGINT, sig_handler);
    // signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		mini.line = NULL;
		print_default(&mini);
		if (mini.line)
		{
			i = 0;
			ft_parse_line(&mini);
			ft_create_pipes_fd(&mini);
			ft_get_here_pipe(&mini);
			if (mini.pipe_count == 0 && ft_check_parent_cmd(&mini))
				ft_parent_cmd(&mini, mini.pipe_line_list[0]);
			else if (mini.pipe_count > 0 && ft_check_parent_cmd(&mini))
				ft_parent_cmd(&mini, mini.pipe_line_list[mini.pipe_count - 1]);
			else
				ft_child_cmd(&mini, i);
			ft_close_pipe_wait_child(&mini, i);
		}
	}
}

// Things left to do
// signal
// Ctrl + C = '\n' if ascii == '\n', print '\n'