/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:50:32 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/02/23 14:31:45 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(void)
{
	char	*temp;
	char	*final;
	char	*str;
	char	*res;

	str = ft_strjoin("\e[0;92m", getenv("USER"));
	temp = ft_strjoin("\e[0;93m", "@minishell$ ");
	final = ft_strjoin(temp, "\e[0m");
	free(temp);
	res = ft_strjoin(str, final);
	// printf("str = %s\n", temp);
	printf("str = %s\n", final);
	printf("str = %s\n", res);
	printf("str = %s\n", str);
	printf("str = \n");
}

// getenv get something from env, etc "PATH"
// str = getenv("USER"), str = lzi-xian
// set colour to the text using res = ft_strjoin(colour, str)
// but this way the colour will keeps colouring the next time of the printf 
// if there is no colour set
// so we would have to ft_strjoin the result with (res, Reset);
// now join the USER to @minishell with different colour and reset
// the output now if you print will be USER@minishell 
// and wont change the next line colour
