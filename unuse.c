// ft_echo.c

// void	ft_check_n(char *s, int *i, int *n)
// {
// 	int	j;
// 	int	k;

// 	j = 0;
// 	while (1)
// 	{
// 		k = 0;
// 		while (s[j] == ' ')
// 			j++;
// 		if (s[j] == '-')
// 			j++;
// 		if (s[j] != 'n')
// 		{
// 			if (s[j] != ' ' || s[j - 2] != ' ')
// 				j--;
// 			break ;
// 		}
// 		while (s[j + k] == 'n')
// 			k++;
// 		if (s[j + k] == '-')
// 		{
// 			j--;
// 			break ;
// 		}
// 		else
// 			j += k;
// 		(*n)++;
// 	}
// 	(*i) += j;
// }

// int	ft_check_space(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] && line[i] == ' ')
// 		i++;
// 	if (line[i])
// 		return (0);
// 	return (1);
// }

// char	*ft_get_ent(char *s)
// {
// 	int		i;
// 	int		l;
// 	char	*ent;

// 	i = 1;
// 	l = 1;
// 	while (s[l] && (ft_isalnum(s[l]) || s[l] == '_'))
// 		l++;
// 	ent = malloc(sizeof(char) * l);
// 	l = 0;
// 	while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
// 	{
// 		ent[l] = s[i];
// 		l++;
// 		i++;
// 	}
// 	ent[l] = '\0';
// 	return (ent);
// }

// void	ft_print_ent(t_mini *mini, int *i)
// {
// 	char	*s;
// 	int		j;

// 	s = ft_get_ent(mini->line + (*i));
// 	j = 0;
// 	if (ft_strlen(s) == 0)
// 	{
// 		while (mini->line[(*i)] == '$')
// 			(*i)++;
// 		printf("$");
// 		return ;
// 	}
// 	while (mini->env[j])
// 	{
// 		if (!(ft_strncmp(s, mini->env[j], ft_strlen(s))))
// 		{
// 			if (mini->env[j][ft_strlen(s)] == '=')
// 			{
// 				printf("%s", mini->env[j] + ft_strlen(s) + 1);
// 				(*i) += ft_strlen(s);
// 				return ;
// 			}
// 		}
// 		j++;
// 	}
// 	(*i) += ft_strlen(s);
// }

// void	ft_echo(t_mini	*mini)
// {
// 	int		i;
// 	int		n;
// 	char	*line;

// 	i = 5;
// 	n = 0;
// 	line = mini->line;
// 	ft_check_n(line + i, &i, &n);
// 	while (line[i])
// 	{
// 		while (line[i] && line[i] == ' ')
// 			i++;
// 		if (line[i] == 39)
// 		{
// 			if (ft_check_quote(line + i, 39))
// 				printf("%c", line[i]);
// 			i++;
// 			while (line[i] && line[i] != 39)
// 			{
// 				if (ft_check_quote(line + i, 39) && line[i] == ' ')
// 					break ;
// 				if (line[i] != 39)
// 					printf("%c", line[i]);
// 				i++;
// 			}
// 			i++;
// 		}
// 		else if (line[i] == 34)
// 		{
// 			if (ft_check_quote(line + i, 34))
// 				printf("%c", line[i]);
// 			i++;
// 			while (line[i] && line[i] != 34)
// 			{
// 				if (ft_check_quote(line + i, 34) && line[i] == ' ')
// 					break ;
// 				if (line[i] != 34)
// 				{
// 					if (line[i] == '$')
// 						ft_print_ent(mini, &i);
// 					else
// 						printf("%c", line[i]);
// 				}
// 				i++;
// 			}
// 			i++;
// 		}
// 		else
// 		{
// 			while (line[i] && line[i] != ' ' && line[i] != 34 && line[i] != 39)
// 			{
// 				if (line[i] == '$')
// 					ft_print_ent(mini, &i);
// 				else
// 					printf("%c", line[i]);
// 				i++;
// 			}
// 		}
// 		if (line[i] && line[i] == ' ')
// 			printf(" ");
// 	}
// 	if (n == 0)
// 		printf("\n");
// }

// ft_cd.c


// void	ft_cd_back(char **env)
// {
// 	char	cwd[PATH_MAX];
// 	char	*new_cwd;
// 	char	*new;
// 	char	*old;
// 	int		i;

// 	getcwd(cwd, sizeof(cwd));
// 	new_cwd = ft_strdup(cwd);
// 	old = new_cwd;
// 	new = ft_trim(new_cwd);
// 	i = 0;
// 	while (env[i])
// 		if (!ft_strncmp(env[i++], "PWD=", 4))
// 			break ;
// 	env[--i] = ft_strjoin("PWD=", new);
// 	i = 0;
// 	while (env[i])
// 		if (!ft_strncmp(env[i++], "OLDPWD=", 7))
// 			break ;
// 	env[--i] = ft_strjoin("OLDPWD=", old);
// 	chdir(new);
// }

// int	ft_cd_check_quote(char *line, int q)
// {
// 	int	i;
// 	int	c;

// 	i = 1;
// 	c = 0;
// 	if (line[0] == q)
// 		c++;
// 	while (line[i])
// 		i++;
// 	if (line[i - 1] == q)
// 		c++;
// 	return (c);
// }

// char	*ft_cd_strdup(char *s1)
// {
// 	char	*dest;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	if ((s1[i] == 34 || s1[i] == 39) && ft_cd_check_quote(s1))
// 		i++;
// 	while (s1[i] )
// 	{
// 		i++;
// 		j++;
// 	}
// 	if (s1[i - 1] == 34 || s1[i - 1] == 39)
// 		j--;
// 	dest = (char *) malloc (sizeof(char) * (j + 1));
// 	i = 0;
// 	if (!dest)
// 		return (0);
// 	while (s1[i] != '\0')
// 	{
// 		dest[i] = s1[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

//minishell.c

// void	print_default(t_mini	*mini)
// {
	// char	*temp;
	// char	*half;
	// char	*end;

	// temp = NULL;
	// temp = ft_strjoin("\e[0;93m", getenv("USER"));
	// //make green user
	// if (!temp)
	// 	temp = ft_strjoin("\e[0;93m", getenv("user"));
	// half = ft_strjoin("\e[0;92m", "@minishell$ ");
	// end = ft_strjoin(half, "\e[0m");
	// free(half);
	// make minishell yellow and wont keep colouring
	// mini->res = ft_strjoin(temp, end);
	// free(temp);
	// free(end);
// }

// void	ft_get_file(t_mini *mini)
// {
// 	DIR				*d;
// 	struct dirent	*dir;
// 	int				l;
// 	int				i;

// 	l = 0;
// 	i = 0;
// 	d = opendir(".");
// 	if (d)
// 	{
// 		dir = readdir(d);
// 		if (!dir)
// 			return ;
// 		while ((dir) != NULL)
// 		{
// 			dir = readdir(d);
// 			l++;
// 		}
// 		closedir(d);
// 	}
// 	mini->file = malloc(sizeof (char *) * l + 1);
// 	d = opendir(".");
// 	if (d)
// 	{
// 		dir = readdir(d);
// 		if (!dir)
// 			return ;
// 		while ((dir) != NULL)
// 		{
// 			mini->file[i] = ft_strdup(dir->d_name);
// 			i++;
// 		}
// 		closedir(d);
// 	}
// 	mini->file[i] = NULL;
// }


// void	ft_get_here_list(t_mini *mini, char *line)
// {
// 	int		i;
// 	char	**temp;

// 	i = 0;
// 	while (mini->here_list[i])
// 		i++;
// 	temp = malloc(sizeof(char *) * (i + 2));
// 	i = 0;
// 	while (mini->here_list[i])
// 	{
// 		temp[i] = ft_strdup(mini->here_list[i]);
// 		free(mini->here_list[i]);
// 		i++;
// 	}
// 	temp[i++] = ft_strdup(line);
// 	temp[i] = NULL;
// 	free(mini->here_list);
// 	mini->here_list = temp;
// }

// void	ft_handle_heredoc_file(t_mini *mini, int n)
// {
// 	int		i;
// 	int		l;
// 	int		fd;
// 	char	***list;

// 	i = 0;
// 	l = 0;
// 	list = &mini->pipe_line_list[n];
// 	while ((*list)[i])
// 	{
// 		if (!ft_strncmp((*list)[i], "<<", 3))
// 		{
// 			l++;
// 			if ((*list)[i + 1])
// 			{
// 				fd = open(".heredoc_tmp", O_TRUNC | O_CREAT | O_WRONLY, 0644);
// 				while (1)
// 				{
// 					print_heredoc(mini, (*list)[i + 1]);
// 					if (!ft_strncmp(mini->heredoc_line, (*list)[i + 1], (ft_strlen((*list)[i + 1]) + 1)))
// 						break ;
// 					write(fd, mini->heredoc_line, ft_strlen(mini->heredoc_line));
// 					write(fd, "\n", 1);
// 				}
// 				dup2(fd, 0);
// 				close(fd);
// 			}
// 			else
// 				perror("parse");
// 		}
// 		i++;
// 	}
// 	*list = ft_remove_here_from_list(list, l);
// }

// void	print_heredoc(t_mini *mini, char *end)
// {
// 	mini->heredoc = ft_strdup("heredoc > ");
// 	mini->heredoc_line = readline(mini->heredoc);
// 	if (mini->heredoc_line)
// 		add_history(mini->heredoc_line);
// }

// void	ft_remove_nl(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '\n')
// 			s[i] = '\0';
// 		i++;
// 	}
// }

// if (!ft_strncmp((*list)[i], "<<", 3))
// 		{
// 			l++;
// 			if ((*list)[i + 1])
// 			{
				// fd = open(".heredoc_tmp", O_TRUNC | O_CREAT | O_WRONLY, 0644);
				// pipe(mini->here_fd);
				// while (1)
				// {
				// 	write(1, "heredoc > ", 10);
				// 	mini->heredoc_line = get_next_line(0);
				// 	ft_remove_nl(mini->heredoc_line);
				// 	if (!ft_strncmp(mini->heredoc_line, (*list)[i + 1], (ft_strlen((*list)[i + 1])) + 1))
				// 		break ;
				// 	write(mini->here_fd[1], mini->heredoc_line, ft_strlen(mini->heredoc_line));
				// 	write(mini->here_fd[1], "\n", 1);
				// 	free(mini->heredoc_line);
				// }
				// free(mini->heredoc_line);
				// close(fd);
				// fd = open(".heredoc_tmp", O_RDONLY);
				// close(fd);
				// dup2(mini->here_fd[mini->here_id][0], 0);
				// close(mini->here_fd[mini->here_id][0]);
				// close(mini->here_fd[mini->here_id][1]);
				// mini->here_id++;
			// }