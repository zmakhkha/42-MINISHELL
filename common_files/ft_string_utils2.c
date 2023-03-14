/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:58:29 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/14 20:02:54 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_token	*ft_strtok(char *str)
{
	int		i;
	int		j;
	t_token	*lst;

	if (!str)
		ft_exit("Null Command", 1);
	j = 0;
	lst = NULL;
	while (str[j])
	{
		while (ft_is_whitespace(str[j]))
			j++;
		i = j;
		if (ft_isalnum(str[j]))
			white_comm(str, &lst, &i, &j);
		else if (str[j] && str[j] == '\'')
			s_quotes(str, &lst, &i, &j);
		else if (str[j] && str[j] == '"')
			d_quotes(str, &lst, &i, &j);
		else if (str[j] == '(')
			ft_prt(str, &lst, &i, &j);
		else
			ft_operators(str, &lst, &i, &j);
	}
	return (lst);
}
