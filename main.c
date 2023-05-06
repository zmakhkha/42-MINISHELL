/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:21 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/06 07:41:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	l(void)
{
	system("leaks minishell");
}

int	main(void)
{
	// atexit(l);
	ft_prompt();
	// char	*a = ft_hdoc_tofd(ft_heredoc("-"));
	// printf("------>%s\n\n", a);
	return (0);
}
