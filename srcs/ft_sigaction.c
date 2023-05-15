/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigaction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:00:56 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/15 20:46:34 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int signo)
{
	ft_putendl_fd("", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
