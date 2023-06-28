/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:55:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/28 05:33:21 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int ft_containequl(char *str)
{
	int	i;

	i=0;
	while(str[i] && str[i])
	{
		if (str[i] == '=')
			return(true);
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
		if (lst && (lst->type == WORD) && (lst->prev->type == WORD) \
		&& ft_containequl(lst->str) && !ft_containequl(lst->prev->str))
		{
			s_tmp = ft_join_free(lst->str, lst->prev->str);
			free(lst->str);
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
	if(r)
	{
		
	res = ft_calloc(3, sizeof(char*));
	i = 0;
	while(r && r[i] && r[i] != del)
		i++;
	if (!r || r[i] == del)
		res[0] = ft_substr(r, 0, i);
	if(!r){
		res[1] = NULL;	
		return (res);	
	}
	i++;
		res[1] = ft_substr(r, i, ft_strlen(r));
	}
	return(res);
}

int	ft_isvalidkey(char *str)
{
	int	i;

	i = 0;
	if(!str || (!isalpha(str[i]) && str[i] != '_'))
		return(false);
	while(str[i])
	{
		if((!ft_isalpha(str[i]) && str[i] != '_' )|| (str[ft_strlen(str) - 1] == ' '))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

void	ft_addnode(t_token *lst, t_env **env){
	

	char	**tmp;
	if (lst)
	{
		puts(lst->str);
		while(lst)
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




void	ft_merge_num_word(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && (lst->type == DIGITE) && (lst->prev->type == WORD))
		{
			s_tmp = ft_join_free(lst->str, lst->prev->str);
			free(lst->str);
			lst->str = s_tmp;
			ft_remove_tok(list, lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
}

void	ft_format_print(t_env *env)
{
	while(env)
	{
		printf("declare -x ");
		if (!ft_strcmp(env->value, "-1"))
			printf("%s=\n", env->key);
		else
			printf("%s=\"%s\"\n", env->key, env->value);
		env = env->next;
	}
}

void	ft_makekey_value(t_token *lst, t_env **env)
{
	int	i;
	char	*key;
	char	*val;

	while(lst)
	{
		key = NULL;
		val = NULL;
		i = 0;
		if (!ft_strchr(lst->str, '='))
		{
			change_env(lst->str, ft_strdup("-1"), env);
			lst = lst->prev;
			continue ;
		}
		while(lst->str[i] && lst->str[i] != '=')
			i++;
		if (lst->str[i] == '=')
		{
			key = ft_substr(lst->str, 0 , i);
			key = ft_rm__exp(key, *env, key, 0);
			if (ft_isvalidkey(key))
			{
				val = ft_substr(lst->str, i +1, ft_strlen(lst->str));
				if (!val)
					val = ft_strdup("");
			}
			else
			{
				printf("export: `%s' : not a valid identifier\n", lst->str);
				key = NULL;
				lst = lst->prev;
				continue ;
			}
		}
		change_env(key, ft_rm__exp(val, *env, val, 0), env);
		// printf("(%s::%s)\n", key, val);
		lst = lst->prev;
	}
}
void	ft_handle_one(char *s, t_env **env)
{
	(void)env;
	t_token	*lst;

	lst = ft_strtok(s);
	ft_mergewords(&lst);
	ft_mergewordspace(&lst);
	ft_merge_num_word(&lst);
	ft_mergeword_num(&lst);
	ft_rm_space_(&lst);
		ft_makekey_value(lst, env);
	// puts("\nprinting our list\n-----");
	// while(lst)
	// {
	// 	printf("(%s)\n", lst->str);
	// 	lst = lst->prev;
	// }
	
}


//validated
void	ft_export_it(t_token *list, t_env **env)
{
	if (ft_lstlen(list) == 1 && \
	!ft_strcmp(ft_strtrim(list->str, " "), "export"))
		ft_format_print(*env);
	else
		ft_handle_one(list->str + 6, env);
}

#define QUOTE -10
void	ft_changetype(t_token **t)
{
	t_token *tmp= *t; 
	while (t && tmp)
	{
		if (ft_strchr(tmp->str, '\''))
			tmp->type = QUOTE;
		tmp = tmp->prev;
	}
}

char    **ft_tokto2dstr(t_token *tok)
{
    char    **res;
    int     i;
	t_token	*tmp;

	tmp = tok;
    i = ft_lstlen(tmp);
    res = NULL;
	tmp = tok;
    if (tmp)
    {
        res = ft_calloc(i + 1, sizeof(char *));
		i = -1;
        while(tok)
        {
            res[++i] = ft_strdup(ft_strtrim(tok->str, " "));
            tok = tok->prev;
        }
    }
    i = 0;
    return (res);
}

char    **ft_split_command(char *str)
{
    t_token *tok;
    char    **res;

    res = NULL;
    tok = ft_strtok1(str);
	ft_mergewords(&tok);
	ft_rm_space_(&tok);
    res = ft_tokto2dstr(tok);
    return (res);
}

int ft_execution(t_token *list, t_env *env)
{
    char    **splited;
    char    *str;

    splited = NULL;
    str = NULL;
    
    if (!list)
        return (EXIT_FAILURE);
    if (list->type == PIPE || list->type == AND || list->type == OR || \
        list->type == Empty)
        g_status = execute_logical_op(list, env);
    if (list->type == WORD)
    {
        str = ft_main_exp(list->str,env);
        splited = ft_split_command(str);

        if (!splited)
         return (EXIT_FAILURE);
        if (is_builtin(splited))
        	g_status = execute_builtin(splited, env);
        else
        	g_status = execute_command(splited, env);
        ft_free_2dstr(splited);
    }
    return (g_status);
}
