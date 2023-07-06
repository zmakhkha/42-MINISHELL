/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:44:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/06 16:33:04 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_str	*ft_add_str(char *str)
{
	t_str	*tmp;

	if (!str)
		return (NULL);
	tmp = (t_str *) malloc(sizeof(t_str));
	if (!tmp)
		ft_exit("str allocation failed", 1);
	tmp->str = str;
	tmp->prev = NULL;
	return (tmp);
}

void	ft_str_addback(t_str **lst, t_str *new)
{
	t_str	*pos;

	if (*lst == NULL)
		*lst = new;
	else
	{
		pos = *lst;
		while (pos -> prev != NULL)
			pos = pos -> prev;
		pos -> prev = new;
	}
}

// free all the list from the called location
void	ft_free_str(t_str **t)
{
	if (t && *t)
	{
		ft_free_str(&(*t)->prev);
		if ((*t) && (*t)->str)
			free((*t)->str);
		(*t)->str = NULL;
		if (*t)
			free(*t);
		(*t) = NULL;
	}
	t = NULL;
}

// this should not be here but for norm purposes
char	*ft_rm__exp(char *str, t_env *env, char *res, int i)
{
	res = ft_rmsq(str);
	i = 0;
	if (res)
	{
		while (res && res[i] != '\0')
		{
			if (res[i] == '$')
				res = ft_expand(res, env);
			i++;
		}
	}
	return (res);
}
