/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_c.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:56:02 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 17:44:16 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_C_H
# define LIB_C_H

# include "../check_is/check_is.h"
# include "../define.h"
# include <stddef.h> /* typedef : size_t */
# include <stdlib.h> /* free, malloc */
/* ******_Libc functions_****** */

long int	ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_itoa(int n);
int			ft_strcmp(const char *s1, const char *s2);

#endif