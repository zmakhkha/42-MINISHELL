/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:26:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/06 17:47:07 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header.h"

void	ft_chng_val(t_env *copy)
{
	char	*tmp;

	tmp = copy->key;
	copy->key = copy->next->key;
	copy->next->key = tmp;
	tmp = copy->value;
	copy->value = copy->next->value;
	copy->next->value = tmp;
}

void	ft_sort_print_env(t_env *env)
{
	declare_env(&env);
}

int	ft_export_it(t_token *list, t_env **env)
{
	char	*tmp;
	int		stat;

	tmp = ft_strtrim(list->str, " ");
	if (ft_lstlen(list) == 1 && !ft_strcmp(tmp, "export"))
	{
		ft_sort_print_env(*env);
		g_glob.g_exp = EXIT_SUCCESS;
	}
	else
		ft_handle_one(list->str + 6, env);
	free(tmp);
	stat = g_glob.g_exp;
	return (stat);
}
