/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:21:31 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:51:38 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putptr(unsigned long int n, int l)
{
	char	*h;

	h = "0123456789abcdef";
	if (n >= 0)
	{
		if (n / 16 > 0)
			l = ft_pf_putptr(n / 16, l);
		l = ft_pf_putchar(h[n % 16], l);
	}
	return (l);
}

int	ft_pf_getptr(unsigned long int n, int l, t_pf_list *f)
{
	if (f->fdot == 1 && n == 0)
	{
		l = ft_pf_putchar('0', l);
		l = ft_pf_putchar('x', l);
		return (l);
	}
	l = ft_pf_putchar('0', l);
	l = ft_pf_putchar('x', l);
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
	l = ft_pf_putptr(n, l);
	return (l);
}
