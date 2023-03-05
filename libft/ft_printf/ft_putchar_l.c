/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:32:59 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:49:13 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_list	*ft_pf_putchar_flags(t_pf_list *f)
{
	f->fhash = 0;
	f->fspace = 0;
	f->fdot = 0;
	f->fplus = 0;
	if (f->fnum < 2)
		f->fnum = 0;
	f->fnum--;
	f->fzero = 0;
	return (f);
}

int	ft_pf_putchar_l(char c, int l)
{
	(void)c;
	l++;
	return (l);
}
