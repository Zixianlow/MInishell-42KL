/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:45:03 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/21 15:13:45 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_pf_list
{
	int	fhash;
	int	fspace;
	int	fdot;
	int	fplus;
	int	fminus;
	int	fnum;
	int	fzero;
}	t_pf_list;

int			ft_printf(const char *s, ...);
int			ft_pf_atoi(const char *str);
t_pf_list	*ft_pf_initflags(t_pf_list *f);
t_pf_list	*ft_pf_percent_flags(t_pf_list *f);
int			ft_pf_chkflags(const char s);
t_pf_list	*ft_pf_init_set_flags(t_pf_list *f, const char *s);
int			ft_pf_print_front(t_pf_list *f, int l, const char s);
int			ft_pf_print_back(t_pf_list *f, int l);
int			ft_pf_printing(const char s, va_list p, int l, t_pf_list *f);
int			ft_pf_putchar(char c, int l);
int			ft_pf_putchar_l(char c, int l);
int			ft_pf_puthexa(unsigned int n, int fd, int type);
int			ft_pf_gethexa(unsigned int n, int fd, int type, t_pf_list *f);
int			ft_pf_puthexa_l(unsigned int n, int l, int type);
int			ft_pf_gethexa_l(unsigned int n, int l, int type, t_pf_list *f);
int			ft_pf_getnbr(int n, int l, t_pf_list *f);
int			ft_pf_putnbr(int n, int l);
int			ft_pf_getnbr_l(int n, int l, t_pf_list *f);
int			ft_pf_putnbr_l(int n, int l);
int			ft_pf_putpercent(t_pf_list *f, int l);
int			ft_pf_putptr(unsigned long int n, int l);
int			ft_pf_getptr(unsigned long int n, int l, t_pf_list *f);
int			ft_pf_putptr_l(unsigned long int n, int l, t_pf_list *f);
int			ft_pf_putstr(char *s, int l, t_pf_list *f);
int			ft_pf_putstr_l(char *s, int l);
int			ft_pf_putunsign(unsigned int n, int l, t_pf_list *f);
int			ft_pf_putunsign_l(unsigned int n, int l, t_pf_list *f);
t_pf_list	*ft_pf_putchar_flags(t_pf_list *f);
t_pf_list	*ft_pf_puthexa_flags(t_pf_list *f, int l);
t_pf_list	*ft_pf_putnbr_flags(t_pf_list *f, int l);
t_pf_list	*ft_pf_putptr_flags(t_pf_list *f, int l);
t_pf_list	*ft_pf_putstr_flags(t_pf_list *f, int l);
t_pf_list	*ft_pf_putunsign_flags(t_pf_list *f, int l);

#endif