/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:26:01 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/22 14:29:09 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include "../define.h"
# include "../includes.h"

/* *****_linkedlist_****** */

t_env	*ft_lstnew(char *key, char *value);
void	ft_lstadd_front(t_env **lst, t_env *new);
int		ft_lstsize(t_env *lst);
t_env	*ft_lstlast(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);
void	ft_lstdelone(t_env *lst, void (*del)(void *));
void	ft_lstiter(t_env *lst, void (*f)(void *));
void	ft_lstclear(t_env **lst, void (*del)(void *));
t_env	*ft_lstmap(t_env *lst, void *(*f)(void *), void (*del)(void *));

#endif