/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:31:50 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:50:36 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_list	*ft_pf_putnbr_num_zero_space_flags(t_pf_list *f, int l)
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
	if (f->fspace == 1 && l == 0)
		f->fspace = 0;
	return (f);
}

t_pf_list	*ft_pf_putnbr_flags(t_pf_list *f, int l)
{
	f->fhash = 0;
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
	f = ft_pf_putnbr_num_zero_space_flags(f, l);
	return (f);
}

int	ft_pf_putnbr_l(int n, int l)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			l = ft_pf_putchar_l('2', l);
			n = -147483648;
		}
		n = -n;
	}
	if (n >= 0)
	{
		if (n / 10 > 0)
			l = ft_pf_putnbr_l(n / 10, l);
		l = ft_pf_putchar_l(n % 10 + '0', l);
	}
	return (l);
}

int	ft_pf_getnbr_l(int n, int l, t_pf_list *f)
{
	if (f->fdot == 1 && n == 0)
		return (l);
	l = ft_pf_putnbr_l(n, l);
	if (n < 0)
	{
		if (f->fspace == 1)
			f->fspace = 0;
		f->fplus = 0;
		f->fdot++;
		l++;
		return (l);
	}
	return (l);
}
