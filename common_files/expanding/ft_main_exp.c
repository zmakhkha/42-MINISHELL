/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:29:02 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/01 10:56:05 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char *ft_expand(char *str, t_env *env)
{
	int i = 0;
	int j = 0;
	char *res = NULL;
	char *tmp_val = NULL;

	while (str[i] && str[i] != '$')
		i++;

	if (str[i] && str[i] == '$')
	{
		res = ft_join_free(res, ft_substr(str, j, i - j));

		j = i + 1;
		while (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
			j++;

		tmp_val = ft_substr(str, i + 1, j - i - 1);
		char *expanded_val = get_value(tmp_val, env);
		free(tmp_val);

		res = ft_join_free(res, expanded_val);
		i = j;
	}

	if (str[j])
		res = ft_join_free(res, ft_substr(str, j, ft_strlen(str) - j));

	free(str);
	return res;
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
	if (str)
		free (str);
	str = NULL;
	return (spl);
}

void	ft_strrep(char *str, char a, char b)
{
	int	i;

	i = -1;
	while(str[++i])
	{
		if (str[i] == a)
			str[i] = b;
	}
}

// expand a string command just before execve
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
	ft_mergeword_num(&lst);
	// ft_merge_sp(&lst);
	tmp = lst;
	while (lst)
	{
		if (lst->str[0] == '\'' || lst->str[0] == '\"')
			ft_strrep(lst->str, ' ', ' ' * -1);
		if (lst->str[0] != '\"' && lst->str[0] != '\'' && \
			ft_strchr(lst->str, '*'))
			lst->str = ft_main_wc(lst->str, env);
		if (lst->str[0] != '\'')                                   // && lst->str && ft_strchr(lst->str, '*')
			lst->str = ft_rm_exp(lst->str, env);
		else if (lst->str[0] == '\"')
		{
			lst->str = ft_strtrim(lst->str, "\"");
			a = 1;
		}
		else if (lst->str[0] == '\'' && !a)
			lst->str = ft_strtrim(lst->str, "\'");
		lst = lst->prev;
	}
	s_tmp = ft_toktostr(tmp);
	res = ft_split(s_tmp, ' ');
	a = -1;
	while(res[++a])
		ft_strrep(res[a], ' ' * -1, ' ');
	ft_free_token(&tmp);
	return (res);
}
