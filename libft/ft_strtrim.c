/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:25:10 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/12 15:36:29 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkstr(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	trimmedlen(char const *s1, char const *set)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (checkstr(*s1, set))
		s1++;
	if (*s1 == '\0')
		return (c);
	i = ft_strlen(s1) - 1;
	while (checkstr(s1[i], set))
		i--;
	while (c <= i)
		c++;
	return (c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	p = (char *) malloc (sizeof(char) * (trimmedlen(s1, set) + 1));
	if (!p)
		return (NULL);
	p[trimmedlen(s1, set)] = 0;
	while (checkstr(*s1, set))
		s1++;
	if (*s1 == '\0')
		return (p);
	i = ft_strlen(s1) - 1;
	while (checkstr(s1[i], set))
		i--;
	j = 0;
	while (j <= i)
	{
		p[j] = *s1;
		s1++;
		j++;
	}
	return (p);
}
