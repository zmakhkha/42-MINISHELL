/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:26:38 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/17 18:00:51 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	white_comm(char *str, t_token **lst, int *a, int *b)
{
	int		j;
	char	*s;

	j = *b;
	while (str[(*b)] && ft_is_valid_comm(str[*b]))
		*b += 1;
	s = ft_substr(str, *a, j - *a + 1);
	ft_token_addback(lst, ft_add_token(s, WORD));
	free(s);
	return ;
}

void	d_quotes(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;

	s = NULL;
	len = ft_strlen(str);
	if (str[*b] && str[*b] == '"')
	{
		*b += 1;
		while (str[*b] && str[*b] != '"')
			*b += 1;
		if (str[*b] == '"')
		{
			s = ft_substr(str, *a + 1, *b - *a -1);
			ft_token_addback(lst, ft_add_token(s, DQ_COMM));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			ft_exit("Double Quotes error !!\n", 1);
		}
	}
	if (s)
		free(s);
}

void	s_quotes(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;

	s = NULL;
	len = ft_strlen(str);
	if (str[*b] && str[*b] == '\'')
	{
		*b += 1;
		while (str[*b] && str[*b] != '\'')
			*b += 1;
		if (str[*b] == '\'')
		{
			s = ft_substr(str, *a + 1, *b - *a -1);
			ft_token_addback(lst, ft_add_token(s, SQ_COMM));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			ft_exit("Signle Quotes error !!\n", 1);
		}
	}
	if (s)
		free(s);
}

void	ft_operators(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	if (ft_voperator(str + *b, '|'))
	{
		write(1, b, 1);
		if (ft_validouble(str + *b, '|'))
		{
			s = ft_substr(str, *a, *a + 2);
			ft_token_addback(lst, ft_add_token(s, OR));
			*b += 2;
		}
		else if (str[*b] == '|')
		{
			s = ft_substr(str, *a, *b + 1);
			ft_token_addback(lst, ft_add_token(s, PIPE));
			*b += 1;
		}
	}
	else if (ft_voperator(str + *b, '&'))
	{
		if (ft_validouble(str + *b, '&'))
		{
			s = ft_substr(str, *a, *b + 2);
			ft_token_addback(lst, ft_add_token(s, AND));
			*b += 2;
		}
	}
	else
		ft_exit("PIPE or OR error !!", 1);
	if (s)
		free (s);
}

// int	ft_istrrchr(const char *s, int c)
// {
// 	int	nbr;

// 	nbr = ft_strlen((char *)s);
// 	c = (char)c;
//     write(1, &s[nbr], 1);
// 	while ((nbr != -1) && s[nbr] != c)
//         nbr--;
// 	if (s[nbr] == c)
// 		return (nbr);
// 	else
// 		return (-1);
// }

// int	ft_istrchr(const char *s, int c)
// {
// 	int	nbr;
// 	int	i;

// 	nbr = ft_strlen((char *)s);
// 	c = (char)c;
// 	i = 0;
// 	while (i < nbr && s[i] != c)
//         i++;
// 	if (s[i] == c)
// 		return (i);
// 	else
// 		return (-1);
// }

// int ft_isvalidparet(char *str)
// {
//     int i;
//     int open;

//     i = -1;
//     open = 0;
//     while(str[++i])
//     {
//         if (str[i] == '(')
//             open++;
//         if (str[i] == ')')
//             open--;
//     }
//     if (!open)
// 	{
// 		printf("----------->haaaaana\n");	
//         return (1);
// 	}
//     return (0);
// }

int if_validp(char* str)
{
	int open;
	int i;

	i = 0;
	open = 1;
	while (str[++i])
	{
		if (str[i] == '(')
		{
			open++;
			if_validp(str + i +1 );
		}
		if (str[i] == ')')
		{	
			open--;
			if (!open)
				return (i);
		}
	}
	if (!open)
		return (i);
	return (-1);
}

// Still to handle multiple parethetises
void	ft_prt(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;

	s = NULL;
	len = ft_strlen(str);
	if (str[*b] && (str[*b] == '(' && if_validp(str + *b) != -1))
	{
		printf("--------->%d\n", *b);
		*b += if_validp(str + *b) ;
		printf("--------->%d\n", *b);
		if (str[*b] == ')')
		{
			s = ft_substr(str, *a + 1, *b - *a -1);
			ft_token_addback(lst, ft_add_token(s, SUBSHELL));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			ft_exit("SUBSHELL Quotes error !!\n", 1);
		}
	}
	else
		ft_exit("SUBSHELL errors !!\n", 1);
	if (s)
		free(s);
}
