/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:53:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 18:12:15 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_H
# define ADD_H

# include "../libc_function/lib_c.h"
# include <stddef.h> /* typedef : size_t */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif