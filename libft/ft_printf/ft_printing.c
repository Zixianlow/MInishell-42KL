/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:15:06 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 14:48:54 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	ft_pf_printing_pid(const char s, va_list p, int l, t_pf_list *f)
{
	if (s == 'p')
	{
		l = ft_pf_print_front(f, l, s);
		l = ft_pf_getptr(va_arg(p, unsigned long int), l, f);
		l = ft_pf_print_back(f, l);
	}
	else if (s == 'd' || s == 'i')
	{
		l = ft_pf_print_front(f, l, s);
		l = ft_pf_getnbr(va_arg(p, int), l, f);
		l = ft_pf_print_back(f, l);
	}
	return (l);
}

int	ft_pf_printing_uxpercent(const char s, va_list p, int l, t_pf_list *f)
{
	if (s == 'u')
	{
		l = ft_pf_print_front(f, l, s);
		l = ft_pf_putunsign(va_arg(p, unsigned int), l, f);
		l = ft_pf_print_back(f, l);
	}
	else if (s == 'x')
	{
		l = ft_pf_print_front(f, l, s);
		l = ft_pf_gethexa(va_arg(p, unsigned int), l, 1, f);
		l = ft_pf_print_back(f, l);
	}
	else if (s == 'X')
	{
		l = ft_pf_print_front(f, l, s);
		l = ft_pf_gethexa(va_arg(p, unsigned int), l, 2, f);
		l = ft_pf_print_back(f, l);
	}
	else if (s == '%')
	{
		l = ft_pf_print_front(f, l, s);
		l = ft_pf_putpercent(f, l);
		l = ft_pf_print_back(f, l);
	}
	return (l);
}

int	ft_pf_printing(const char s, va_list p, int l, t_pf_list *f)
{
	if (s == 'c')
	{
		l = ft_pf_print_front(f, l, s);
		l = ft_pf_putchar(va_arg(p, int), l);
		l = ft_pf_print_back(f, l);
	}
	else if (s == 's')
	{
		l = ft_pf_print_front(f, l, s);
		l = ft_pf_putstr(va_arg(p, char *), l, f);
		l = ft_pf_print_back(f, l);
	}
	l = ft_pf_printing_pid(s, p, l, f);
	l = ft_pf_printing_uxpercent(s, p, l, f);
	free(f);
	if (!(ft_pf_isprint(s)))
		l = ft_pf_putchar(s, l);
	return (l);
}
