/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:14:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/29 01:50:00 by ayel-fil         ###   ########.fr       */
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
		if (!g_status && t)
			ft_main_lexer(t);
		else if (t)
			printf("Lexer Error !!\n");
		if (!g_status && t)
			ft_main_ast(&t);
		else if (t)
			printf("Lexer Error !!\n");
		free (str);
		t = ft_getfirst(t);
		ft_free_tree(&t);
		// system("leaks minishell");
	}
}
