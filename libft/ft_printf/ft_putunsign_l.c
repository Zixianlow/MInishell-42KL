/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:30:17 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:52:50 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_list	*ft_pf_putunsign_num_zero_flags(t_pf_list *f, int l)
{
	if (f->fnum >= l)
	{
		f->fnum = f->fnum - l + 1;
		if (f->fdot == 0 || f->fdot == 1)
			f->fnum--;
	}
	else
		f->fnum = 0;
	if (f->fzero > l)
		f->fzero = f->fzero - l;
	else
		f->fzero = 0;
	return (f);
}

t_pf_list	*ft_pf_putunsign_flags(t_pf_list *f, int l)
{
	f->fhash = 0;
	f->fspace = 0;
	f->fplus = 0;
	if (f->fdot == 1)
		f->fdot = 1;
	else if (f->fdot > l)
		f->fdot = f->fdot - l + 1;
	else
		f->fdot = 0;
	if (f->fdot > 0)
		l = l + f->fdot - 1;
	else
		l = l + f->fdot;
	f = ft_pf_putunsign_num_zero_flags(f, l);
	return (f);
}

int	ft_pf_putunsign_l(unsigned int n, int l, t_pf_list *f)
{
	if (n == 0 && f->fdot == 1)
		return (l);
	if (n >= 0)
	{
		if (n / 10 > 0)
			l = ft_pf_putnbr_l(n / 10, l);
		l = ft_pf_putchar_l(n % 10 + '0', l);
	}
	return (l);
}
