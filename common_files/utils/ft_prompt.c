/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:14:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/03 02:40:06 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// Add a command history
void	ft_prompt(char **env)
{
	char	*str;
	t_token	*t;
	t_env	*env_list;
	t = NULL;
	while (1)
	{
		env_list = set_env(env);
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
			ft_main_ast(&t,&env_list);
		else if (t)
			printf("Lexer Error !!\n");
		free(str);
		t = ft_getfirst(t);
		ft_free_tree(&t);
		// system("leaks minishell");
	}
}
