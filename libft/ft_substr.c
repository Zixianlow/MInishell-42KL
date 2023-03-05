/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:01:33 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/12 12:18:20 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (NULL);
	if (len > (size_t)ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (start > (unsigned int)ft_strlen(s))
		len = 0;
	p = (char *) malloc ((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, (const char *)(s + start), len + 1);
	return (p);
}
