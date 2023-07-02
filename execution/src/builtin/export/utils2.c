/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:22:51 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 13:05:36 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header.h"

int	ft_containequl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i])
	{
		if (str[i] == '=')
			return (true);
		i++;
	}
	return (false);
}

void	ft_mergewordspace(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && (lst->type == WORD) && (lst->prev->type == WORD)
			&& ft_containequl(lst->str) && !ft_containequl(lst->prev->str))
		{
			s_tmp = ft_join_free(lst->str, ft_strdup(lst->prev->str));
			// free(lst->str);
			// detect(s_tmp);
			lst->str = s_tmp;
			ft_remove_tok(list, lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
}

char	**ft_devide(char *r, char del)
{
	int		i;
	char	**res;

	res = NULL;
	if (r)
	{
		res = ft_calloc(3, sizeof(char *));
		i = 0;
		while (r && r[i] && r[i] != del)
			i++;
		if (!r || r[i] == del)
			res[0] = ft_substr(r, 0, i);
		if (!r)
		{
			res[1] = NULL;
			return (res);
		}
		i++;
		res[1] = ft_substr(r, i, ft_strlen(r));
	}
	return (res);
}

int	ft_isvalidkey(char *str)
{
	int	i;

	i = 0;
	if (!str || (!isalpha(str[i]) && str[i] != '_'))
		return (false);
	i++;
	while (str[i])
	{
		if ((!ft_isalnum(str[i]) && str[i] != '_') || (str[ft_strlen(str) \
			- 1] == ' '))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

void	ft_addnode(t_token *lst, t_env **env)
{
	char	**tmp;

	if (lst)
	{
		puts(lst->str);
		while (lst)
		{
			tmp = ft_devide(lst->str, '=');
			if (!tmp)
				add_env_node(lst->str, NULL, env);
			if (ft_isvalidkey(lst->str))
			{
				add_env_node(tmp[0], tmp[1], env);
				free(tmp);
				tmp = NULL;
			}
			else
				lst = lst->prev;
		}
	}
}
