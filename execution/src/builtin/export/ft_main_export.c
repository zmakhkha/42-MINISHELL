/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:26:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/01 21:16:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header.h"

void	ft_export_it(t_token *list, t_env **env)
{
	if (ft_lstlen(list) == 1 && !ft_strcmp(ft_strtrim(list->str, " "),
			"export"))
		ft_print_exp(*env);
		// ft_format_print(*env);
	else
		ft_handle_one(list->str + 6, env);
}