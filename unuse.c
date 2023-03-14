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

