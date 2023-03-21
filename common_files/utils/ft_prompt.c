/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:14:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/20 17:33:28 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// Add a command history
void	ft_prompt(void)
{
	char	*str;
	t_token	*t;

	t = NULL;
	while (1)
	{
		usleep(100);
		str = readline("minishell $ ");
		if (str == NULL)
			break ;
		ft_add_history(str);
		t = ft_strtok(str);
		ft_main_lexer(t);
		free (str);
		ft_free_token(&t);
	}
}
