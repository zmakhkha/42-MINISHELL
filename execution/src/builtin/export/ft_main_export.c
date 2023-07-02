/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:26:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 16:16:08 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header.h"

void	ft_export_it(t_token *list, t_env **env)
{
	char	*tmp;

	tmp = ft_strtrim(list->str, " ");
	if (ft_lstlen(list) == 1 && !ft_strcmp(tmp, "export"))
		ft_print_exp(*env);
	else
		ft_handle_one(list->str + 6, env);
	free(tmp);
}
