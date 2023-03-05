/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:26:48 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/06 16:39:37 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	i = 0;
	if (!s)
		return (NULL);
	p = (char *) malloc (sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = f(i, (char)s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
