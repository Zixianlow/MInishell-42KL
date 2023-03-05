/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_front_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:21:46 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:57:06 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_print_front_plus_hash(t_pf_list *f, int l, const char s)
{
	if (f->fplus == 1)
	{
		write(1, "+", 1);
		l++;
	}
	if (f->fhash == 1)
	{
		write(1, "0", 1);
		write(1, &s, 1);
		l = l + 2;
	}
	return (l);
}

int	ft_pf_print_front(t_pf_list *f, int l, const char s)
{
	if (f->fspace == 1 && f->fplus != 1)
	{
		write(1, " ", 1);
		l++;
	}
	while (f->fnum > 0 && f->fminus == 0)
	{
		if (f->fnum != 1 || f->fplus != 1)
		{
			write(1, " ", 1);
			l++;
		}
		f->fnum--;
	}
	l = ft_pf_print_front_plus_hash(f, l, s);
	return (l);
}

int	ft_pf_print_back(t_pf_list *f, int l)
{
	while (f->fnum > 0)
	{
		write(1, " ", 1);
		l++;
		f->fnum--;
	}
	return (l);
}
