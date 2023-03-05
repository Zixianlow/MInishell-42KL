/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:19:09 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:53:01 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putunsign(unsigned int n, int l, t_pf_list *f)
{
	while (f->fzero > 0)
	{
		write(1, "0", 1);
		l++;
		f->fzero--;
	}
	if (f->fdot == 1 && n == 0)
		return (l);
	while (f->fdot > 2)
	{
		write(1, "0", 1);
		l++;
		f->fdot--;
	}
	if (n >= 0)
	{
		if (n / 10 > 0)
			l = ft_pf_putnbr(n / 10, l);
		l = ft_pf_putchar(n % 10 + '0', l);
	}
	return (l);
}
