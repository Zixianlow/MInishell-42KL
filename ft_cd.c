/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:58:58 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/05 12:37:46 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_trim(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (str[i] != '/')
			i--;
		else
			break ;
	}
	temp = malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		temp[j] = str[j];
		j++;
	}
	if (i == 0)
	{
		temp[j] = str[j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

void	ft_cd_back(char **env)
{
	char	cwd[PATH_MAX];
	char	*new_cwd;
	char	*new;
	char	*old;
	int		i;

	getcwd(cwd, sizeof(cwd));
	new_cwd = ft_strdup(cwd);
	old = new_cwd;
	new = ft_trim(new_cwd);
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
	chdir(new);
}

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

char	*ft_user_input_cwd(char *cwd, char *line)
{
	char	*temp;
	char	*hold;
	// char	*part;
	int		i;

	temp = ft_strjoin(cwd, "/");
	i = 2;
	while (line[i] == ' ')
		i++;
	// part = ft_cd_strdup(line);
	hold = ft_strjoin(temp, line);
	return (hold);
}

void	ft_cd_next(char **env, char *line)
{
	char	cwd[PATH_MAX];
	char	*new_cwd;
	char	*new;
	char	*old;
	int		i;

	getcwd(cwd, sizeof(cwd));
	new_cwd = ft_user_input_cwd(cwd, line);
	old = ft_strdup(cwd);
	if (access(new_cwd, 0) == 0)
		new = new_cwd;
	else
		perror("cd: No such file or directory");
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
	chdir(new);
}

void	ft_cd(char **env)
{
	ft_cd_back(env);
}
