/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:29:02 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/22 16:12:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_expand(char *str, t_env *env)
{
	int		i;
	int		j;
	char	*res;
	char	*tmp_val;

	res = NULL;
	tmp_val = NULL;
	i = 0;
	j = 0;
	while (str[i] && str[i] != '$')
		i++;
	if (str[i] && str[i] == '$')
	{
		res = ft_join_freel(res, &str[j], i - j);
		j = i + 1;
		while (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
			j++;
		tmp_val = ft_substr(str, i + 1, j - i - 1);
		tmp_val = get_value(tmp_val, env);
		res = ft_join_free(res, tmp_val);
		i = j;
	}
	if (str[j])
		res = ft_join_free(res, &str[j]);
	free(str);
	return (res);
}

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

char	*ft_rm_exp(char *str, t_env *env)
{
	int		i;
	int		t;
	char	*res;

	res = NULL;
	t = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			t = 1;
		if (str[i] == '\"')
			t = 2;
		if (t)
			break ;
	}
	if (t == 1)
	{
		res = ft_rmsq(str);
	}
	else
		res = ft_rm__exp(str, env, res, i);
	free(str);
	return (res);
}

int	ft_isquote(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str)
		{
			if ((*str) == '\'' || (*str) == '\"')
				return (1);
		}
	}
	return (0);
}

char	**ft_format(char *str)
{
	char	**spl;

	spl = ft_split(str, ' ');
	free (str);
	str = NULL;
	return (spl);
}

// expand a string command
char	**ft_main_exp(char *str, t_env *env)
{
	t_token	*lst;
	t_token	*tmp;
	char	*s_tmp;
	char	**res;
	int		a;

	a = 0;
	res = NULL;
	s_tmp = NULL;
	lst = NULL;
	lst = ft_strtok(str);
	tmp = lst;
	while (lst)
	{
		if (ft_strchr(lst->str, '$'))
			lst->str = ft_rm_exp(lst->str, env);
		if ((ft_strchr(lst->str, '\'') || ft_strchr(lst->str, '\"')))
		{
			a = 1;
			s_tmp = lst->str;
			lst->str = ft_rm_exp(lst->str, env);

		}
		if (!a && lst->str && ft_strchr(lst->str, '*'))
			lst->str = ft_main_wc(lst->str, env);
		lst = lst->prev;
	}
	s_tmp = ft_toktostr(tmp);
	res = ft_format(s_tmp);
	ft_free_token(&tmp);
	ft_free_token(&lst);
	return (res);
}
