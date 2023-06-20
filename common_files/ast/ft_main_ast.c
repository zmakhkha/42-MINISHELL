/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:58:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/20 23:47:04 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// if type == 0 we should expand else no need to
char	*ft_get_path(char *del, int type, t_env **env_list)
{
	int	a;
	char	*tmp;
	char	*path;
	a = -5;
	path = NULL;
	a = fork();
	if (a == 0)
	{
		puts("haaaaha");
		puts(del);
		tmp = ft_heredoc(del);
		path = ft_strdup(ft_hdoc_tofd(tmp, type, *env_list));
	}
	else
	{
		waitpid(a, NULL, 0);
	}
	return (path);
}

char	*ft_rmsq2(char *str, int len, char c)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';

	return (res);
}

char	*ft_rmsq1(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = 0;
	while (str[i] && (str[i] != '\'' && str[i] != '\"'))
		i++;
	if (str[i])
		c = str[i];
	else
		return (ft_strdup(str));
	i = -1;
	while (str[++i])
	{
		if (str[i] != c)
			len++;
	}
	return (ft_rmsq2(str, len, c));
}

char	*ft_exp1(char *str)
{
	int		i;
	int		t;
	char	*res;

	res = NULL;
	t = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			t = 1;
		if (t)
			break ;
	}
	if (t == 1)
		res = ft_rmsq(str);
	return (res);
}


void	ft_hdoc_to_file(t_token **list, t_env **env_list)
{
	char	*tmp;
	tmp = NULL;
	if (list && (*list) && (*list)->type == HDOC)
	{
		tmp = ft_strtrim((*list)->str, " \t");
		if (ft_strchr(tmp, '\'') || ft_strchr(tmp,  '\"'))
		{
			tmp = ft_exp1((*list)->str);
			(*list)->str = 	ft_get_path(tmp, 0, env_list);
		}
		else
			(*list)->str = 	ft_get_path(tmp, 1, env_list);
		(*list)->type = RE_IN;
	}
}

void	ft_hdocontree(t_token **list, t_env **env_list)
{
	t_token	*lst;
	lst = *list;
	if (list && *list)
	{
		ft_hdocontree(&lst->left, env_list);
		if (lst->type == HDOC)
			ft_hdoc_to_file(&lst, env_list);
		// printf("-->(%d, %s)\n", lst->type, lst->str);
		// ft_hdocontree(&lst, env_list);
		ft_hdocontree(&lst->right, env_list);
		
	}
}

void	ft_printini(t_token **list )
{
	t_token	*lst;
	lst = *list;
	if (list && *list)
	{
		ft_printini(&lst->left);
		printf("(%d, %s)", lst->type, lst->str);
		ft_printini(&lst->right);
		
	}
}

void	ft_main_ast(t_token **list, t_env **env_list)
{
	ft_make_bigops(list);
	ft_pipe_nodes(list);
	ft_leaf_nodes(list);
	ft_hdocontree(list, env_list);
	// ft_printini(list);
	ft_exe_tree(*list, *env_list);
}
