/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:04:13 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/11 14:11:02 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*iter;
	t_list	*temp;

	temp = NULL;
	while (lst)
	{
		iter = ft_lstnew(f(lst -> content));
		if (!iter)
		{
			ft_lstclear(&iter, del);
			return (NULL);
		}
		ft_lstadd_back(&temp, iter);
		lst = lst -> next;
	}
	return (temp);
}
