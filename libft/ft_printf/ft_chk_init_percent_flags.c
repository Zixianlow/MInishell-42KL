/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_init_percent_flags.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:28:48 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:56:10 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_list	*ft_pf_initflags(t_pf_list *f)
{
	f = (t_pf_list *)malloc(sizeof(t_pf_list) * 1);
	if (f == NULL)
		return (NULL);
	f->fhash = 0;
	f->fspace = 0;
	f->fdot = 0;
	f->fplus = 0;
	f->fminus = 0;
	f->fnum = 0;
	f->fzero = 0;
	return (f);
}

t_pf_list	*ft_pf_percent_flags(t_pf_list *f)
{
	f->fhash = 0;
	f->fspace = 0;
	f->fdot = 0;
	f->fplus = 0;
	if (f->fnum > 0)
		f->fnum--;
	if (f->fzero > 0)
		f->fzero--;
	if (f->fminus == 1 && f->fzero != 0)
	{
		f->fnum = f->fzero;
		f->fzero = 0;
	}
	return (f);
}

int	ft_pf_chkflags(const char s)
{
	if (s == '#' || s == ' ' || s == '.')
		return (1);
	else if (s == '+' || s == '-')
		return (1);
	else if (s >= '0' && s <= '9')
		return (1);
	return (0);
}
