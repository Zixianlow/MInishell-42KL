/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:32:25 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:49:48 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_list	*ft_pf_puthexa_num_zero_flags(t_pf_list *f, int l)
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

t_pf_list	*ft_pf_puthexa_flags(t_pf_list *f, int l)
{
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
	f = ft_pf_puthexa_num_zero_flags(f, l);
	if (f->fhash == 1 && f->fnum > 1)
		f->fnum = f->fnum - 2;
	return (f);
}

int	ft_pf_puthexa_l(unsigned int n, int l, int type)
{
	char	*h1;
	char	*h2;

	h1 = "0123456789abcdef";
	h2 = "0123456789ABCDEF";
	if (n < 0)
		n = 4294967295 + n;
	if (n >= 0)
	{
		if (n / 16 > 0)
			l = ft_pf_puthexa_l(n / 16, l, type);
		if (type == 1)
			l = ft_pf_putchar_l(h1[n % 16], l);
		else if (type == 2)
			l = ft_pf_putchar_l(h2[n % 16], l);
	}
	return (l);
}

int	ft_pf_gethexa_l(unsigned int n, int l, int type, t_pf_list *f)
{
	if (n == 0 && f->fhash == 1)
		f->fhash = 0;
	if (n == 0 && f->fdot == 1)
		return (l);
	l = ft_pf_puthexa_l(n, l, type);
	return (l);
}
