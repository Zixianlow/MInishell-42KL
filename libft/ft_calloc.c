/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:47:19 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/13 15:58:23 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	if (size != 0 && count >= SIZE_MAX / size)
		return (NULL);
	p = (char *) malloc (count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
