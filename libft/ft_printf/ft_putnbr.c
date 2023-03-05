/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:16:27 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:50:55 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putnbr(int n, int l)
{
	if (n >= 0)
	{
		if (n / 10 > 0)
			l = ft_pf_putnbr(n / 10, l);
		l = ft_pf_putchar(n % 10 + '0', l);
	}
	return (l);
}

int	ft_pf_getnbr_putdot_zero(int l, t_pf_list *f)
{
	while (f->fzero > 0)
	{
		write(1, "0", 1);
		l++;
		f->fzero--;
	}
	while (f->fdot > 2)
	{
		write(1, "0", 1);
		l++;
		f->fdot--;
	}
	return (l);
}

int	ft_pf_getnbr(int n, int l, t_pf_list *f)
{
	if (f->fdot == 1 && n == 0)
		return (l);
	if (n < 0)
		l = ft_pf_putchar('-', l);
	l = ft_pf_getnbr_putdot_zero(l, f);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			l = ft_pf_putchar('2', l);
			n = -147483648;
		}
		n = -n;
	}
	l = ft_pf_putnbr(n, l);
	return (l);
}
