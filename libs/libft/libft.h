/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooxcoder <fooxcoder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:22:45 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/20 07:35:40 by fooxcoder        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>  /* min and max */
# include <stdarg.h>  /* for variadic functions */
# include <stdbool.h> /* booleans */
# include <stddef.h>  /* typedef : size_t */
# include <stdio.h>   /* testing printf */
# include <stdlib.h>  /* free, malloc */
# include <unistd.h>  /* system call functions */

# define POSITIVE 1
# define NEGATIVE -1

/* ******_Libc functions_****** */
long int			ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
/* *****_Additional functions__****** */
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_substr_gnl(char const *s, unsigned int start,
						size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* *****_bonus_part_****** */
typedef struct s_stack
{
	int				content;
	int				index;
	int				position;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_lstnew(int content);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstdelone(t_stack *lst, void (*del)(int));
void				ft_lstiter(t_stack *lst, void (*f)(int));
void				ft_lstclear(t_stack **lst, void (*del)(int));
t_stack				*ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(int));
/*  *************** ft_printf ************** */
int					ft_putchar(int c);
int					ft_putnbr(int n);
int					ft_putstr(char *string);
int					ft_puthex(unsigned int n, const char *base);
int					ft_putnbr_u(unsigned int n);
int					ft_putaddress(unsigned long long n);
int					ft_printf(const char *string, ...);
int					ft_handler(char charachter, va_list args);
/*  *************** GET_NEXT_LINE ************** */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char				*get_next_line_bonus(int fd);
char				*get_next_line(int fd);

/* ******************* After libft ********************  */
int					ft_strcmp(const char *s1, const char *s2);
double				ft_atof(const char *str);
int					ft_isspace(char c);
int					ft_check_integer(const char *param);
void				ft_free_str_array(char **arr);
void				ft_p2darray(char **array, int fd);

#endif