/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:29:02 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 20:30:59 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_expand(char *str, t_env *env)
{
	int		i;
	int		j;
	char	*res;
	char	*tmp_val;
	char	*expanded_val;

	i = 0;
	j = 0;
	res = NULL;
	while (str && str[i] && str[i] != '$')
		i++;
	if (str && str[i] && str[i] == '$')
	{
		res = ft_join_free(res, ft_substr(str, j, i - j));
		j = i + 1;
		while (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
			j++;
		tmp_val = ft_substr(str, i + 1, j - i - 1);
		expanded_val = get_value(tmp_val, env);
		free(tmp_val);
		res = ft_join_free(ft_strdup(res), ft_strdup(expanded_val));
		i = j;
	}
	if (str && str[j])
		res = ft_join_free(res, ft_substr(str, j, ft_strlen(str) - j));
	return (free(str), res);
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
	if (str)
		free(str);
	return (res);
}

void	ft__main_exp(t_token *lst, t_env *env)
{
	int		a;

	a = 0;
	if (lst->str[0] == '\'' || lst->str[0] == '\"')
		ft_strrep(lst->str, ' ', ' ' * -1);
	if (lst->str[0] != '\"' && lst->str[0] != '\'' && ft_strchr(lst->str, \
		'*'))
		lst->str = ft_main_wc(lst->str, env);
	if (lst->str && lst->str[0] != '\'')
		lst->str = ft_rm_exp(lst->str, env);
	else if (lst->str && lst->str[0] == '\"')
	{
		lst->str = ft_strtrim(lst->str, "\"");
		a = 1;
	}
	else if (lst->str && lst->str[0] == '\'' && !a)
		lst->str = ft_strtrim(lst->str, "\'");
}

// expand a string command just before execve
char	**ft_main_exp(char *str, t_env *env)
{
	t_token	*lst;
	t_token	*tmp;
	char	*s_tmp;
	char	**res;
	int		a;

	res = NULL;
	s_tmp = NULL;
	lst = NULL;
	lst = ft_strtok(str);
	ft_mergeword_num(&lst);
	tmp = lst;
	while (lst)
	{
		ft__main_exp(lst, env);
		lst = lst->prev;
	}
	s_tmp = ft_toktostr(tmp);
	res = ft_split(s_tmp, ' ');
	a = -1;
	while (res && res[++a])
		ft_strrep(res[a], ' ' * -1, ' ');
	ft_free_token(&tmp);
	free(s_tmp);
	return (res);
}
