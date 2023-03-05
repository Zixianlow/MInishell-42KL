/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:18:51 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/16 12:58:00 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chksep(char ch, char c)
{
	int	i;

	i = 0;
	if (ch == c)
		return (1);
	return (0);
}

static int	ft_strcount(char *str, char c)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_chksep(str[i], c))
			i++;
		if (str[i] != '\0')
			q++;
		while (str[i] != '\0' && !ft_chksep(str[i], c))
			i++;
	}
	return (q + 1);
}

static int	ft_sublen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ft_chksep(str[i], c) == 0)
		i++;
	return (i + 1);
}

static char	*word(const char *str, char c)
{
	int		j;
	int		l;
	char	*dest;

	l = ft_sublen((char *)str, c);
	dest = (char *)malloc(sizeof(char) * l);
	if (dest == NULL)
		return (0);
	j = 0;
	while (j < l - 1)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	char	**dest;

	if (!str)
		return (NULL);
	dest = (char **) malloc(sizeof(char *) * (ft_strcount((char *)str, c)));
	if (dest == NULL)
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_chksep(str[i], c) == 1)
			i++;
		if (str[i] != '\0')
		{
			dest[j] = word(&str[i], c);
			j++;
		}
		while (str[i] != '\0' && ft_chksep(str[i], c) == 0)
			i++;
	}
	dest[j] = 0;
	return (dest);
}
