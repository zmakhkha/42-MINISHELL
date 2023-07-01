/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:21:50 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/01 11:47:19 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header.h"

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



// void	ft_format_print(t_env *env)
// {
//     char    *min;
    
//     while(env && env->next)
//     {
//         min = env->key;
//         if (ft_strcmp(min, ))
//     }
// 	while(env)
// 	{
// 		printf("declare -x ");
// 		if (!ft_strcmp(env->value, "-1"))
// 			printf("%s=\n", env->key);
// 		else
// 			printf("%s=\"%s\"\n", env->key, env->value);
// 		env = env->next;
// 	}
// }

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