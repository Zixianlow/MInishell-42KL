/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:30:59 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:51:52 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_list	*ft_pf_putstr_flags(t_pf_list *f, int l)
{
	if (f->fminus == 1 && f->fzero != 0)
	{
		f->fnum = f->fzero;
		f->fzero = 0;
	}
	f->fhash = 0;
	f->fspace = 0;
	f->fplus = 0;
	if (l > f->fdot && f->fdot != 0)
		l = f->fdot;
	if (f->fnum >= l)
	{
		f->fnum = f->fnum - l;
		if (f->fdot == l && l != 0)
		f->fnum++;
	}
	else
		f->fnum = 0;
	if (f->fzero > l)
		f->fzero = f->fzero - l;
	else
		f->fzero = 0;
	return (f);
}

int	ft_pf_putstr_l(char *s, int l)
{
	int	i;

	i = 0;
	if (!s)
	{
		l = ft_pf_putstr_l("(null)", l);
		return (l);
	}
	while (s[i])
	{
		l = ft_pf_putchar_l(s[i], l);
		i++;
	}
	return (l);
}
