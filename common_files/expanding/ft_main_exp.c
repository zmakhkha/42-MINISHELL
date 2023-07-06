/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:29:02 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/05 20:46:59 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static char	*ft__expand(char *str, t_env *env, int	*i, int *j)
{
	char	*res;
	char	*tmp_val;
	char	*expanded_val;

	res = NULL;
	res = ft_join_free(res, ft_substr(str, *j, *i - *j));
	*j = *i + 1;
	while (str[*j] && (ft_isalnum(str[*j]) || str[*j] == '_'))
		*j += 1;
	tmp_val = ft_substr(str, *i + 1, *j - *i - 1);
	expanded_val = get_value(tmp_val, env);
	free(tmp_val);
	res = ft_join_free(res, ft_strdup(expanded_val));
	return (res);
}

char	*ft_expand(char *str, t_env *env)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = NULL;
	while (str && str[i] && str[i] != '$')
		i++;
	if (str && str[i] && str[i] == '$' && str[i + 1] && \
	ft_isalpha(str[i + 1]))
	{
		res = ft__expand(str, env, &i, &j);
		i = j;
	}
	if (str && str[j])
		res = ft_join_free(res, ft_substr(str, j, ft_strlen(str) - j));
	free(str);
	str = NULL;
	return (res);
}

static void	ft___main_exp(t_token *lst, t_env *env, int i)
{
	if (lst->str && lst->str[0] && \
	lst->str && lst->str[0] != '\'' && ft_strchr(lst->str, '$'))
		lst->str = ft_expand(lst->str, env);
	if (lst->str && (lst->str[0] == '\'' || lst->str[0] == '\"'))
		ft_strrep(lst->str, ' ', ' ' * -1);
	if (lst->str && lst->str[0] != '\"' && \
	lst->str[0] != '\'' && ft_strchr(lst->str, '*') && !i)
		lst->str = ft_main_wc(lst->str, env);
}

void	ft__main_exp(t_token *lst, t_env *env, int i)
{
	int		a;
	char	*t;

	t = NULL;
	a = 0;
	ft___main_exp(lst, env, i);
	if (lst->str && lst->str[0] != '\'')
		lst->str = ft_rm_exp(lst->str, env);
	else if (lst->str && lst->str[0] == '\"')
	{
		lst->str = ft_strtrim(lst->str, "\"");
		a = 1;
	}
	else if (lst->str && lst->str[0] == '\'' && !a)
	{
		t = lst->str;
		lst->str = ft_strtrim(lst->str, "\'");
		free(t);
	}
}

// expand a string command just before execve
char	**ft_main_exp(char *str, t_env *env, int i)
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
		ft__main_exp(lst, env, i);
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
