/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:59:24 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/13 19:32:39 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chk(const char *haystack, const char *needle, size_t i, size_t j)
{
	if ((char)haystack[i + j] != (char)needle[i])
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	q;
	size_t	j;

	if (!haystack && !len)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	j = 0;
	while ((char)haystack[j] != '\0' && j < len)
	{
		if ((char)haystack[j] == *(char *)needle)
		{
			i = -1;
			q = 0;
			while ((char)needle[++i] != '\0')
				if (chk(haystack, needle, i, j) == 1 || (i + j == len))
						q++;
			if (q == 0)
				return ((char *)(haystack + j));
		}
		j++;
	}
	return (0);
}
