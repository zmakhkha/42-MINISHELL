/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:01:55 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/13 16:39:28 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_patch(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == "\"")
		{		
		}
	}
}

t_token	*tokenize_it(char *str)
{
	t_token	*tmp;

	if (!str)
		return (NULL);
	tmp = (t_token *) malloc(sizeof(t_token));
	if (!tmp)
		ft_exit("Token allocation failed", 1);
	if (str == "&&" || str == "||" || str == "|")
	{	
		tmp->len = ft_strlen(str);
		tmp->str = str;
		tmp->type = OPERATOR;
	}
}

void	free_token(t_token *t)
{
	if (!t)
		return ;
	if (t -> str)
		free(t->str);
	return (free(t), 0);
}
