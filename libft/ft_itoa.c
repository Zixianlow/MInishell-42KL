/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:01:44 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/11 19:10:24 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*calc(int n, char *p, int i)
{
	if (n == 0)
		p[0] = '0';
	if (n < 0)
	{
		p[0] = '-';
		if (n == -2147483648)
		{
			p[1] = '2';
			n = -147483648;
		}
		n = -n;
	}
	while (n > 0)
	{
		p[i--] = n % 10 + '0';
		n /= 10;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;

	p = (char *) malloc (sizeof(char) * (intlen(n) + 1));
	if (!p)
		return (NULL);
	i = intlen(n) - 1;
	p[i + 1] = '\0';
	p = calc(n, p, i);
	return (p);
}

// int main()
// {
// 	printf("%s\n", ft_itoa(-4516376));
// }