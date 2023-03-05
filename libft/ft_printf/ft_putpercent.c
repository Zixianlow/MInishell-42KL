/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:36:37 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:51:04 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putpercent(t_pf_list *f, int l)
{
	while (f->fzero > 0)
	{
		write(1, "0", 1);
		l++;
		f->fzero--;
	}
	l = ft_pf_putchar('%', l);
	return (l);
}
