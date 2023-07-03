/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:26:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/03 12:06:34 by zmakhkha         ###   ########.fr       */
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
	t_env	*copy;
	t_env	*pos;
	int		i;

	pos = env;
	while (pos)
	{
		copy = pos;
		i = 0;
		while (copy && copy->next)
		{
			if (ft_strcmp(copy->key, copy->next->key) > 0)
			{
				ft_chng_val(copy);
				i = 1;
			}
			if (i)
				break ;
			copy = copy->next;
		}
		if (i == 1)
			continue ;
		pos = pos->next;
	}
	ft_print_exp(env);
}

void	ft_export_it(t_token *list, t_env **env)
{
	char	*tmp;

	tmp = ft_strtrim(list->str, " ");
	if (ft_lstlen(list) == 1 && !ft_strcmp(tmp, "export"))
	{
		ft_sort_print_env(*env);
	}
	else
		ft_handle_one(list->str + 6, env);
	free(tmp);
}
