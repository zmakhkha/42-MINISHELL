/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:02:26 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/17 17:46:31 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include<libc.h>
# include"header.h"


// int	ft_istrrchr(const char *s, int c)
// {
// 	int	nbr;

// 	nbr = ft_strlen((char *)s);
// 	c = (char)c;
//     write(1, &s[nbr], 1);
// 	while ((nbr != -1) && s[nbr] != c)
//         nbr--;
// 	if (s[nbr] == c)
// 		return (nbr + 1);
// 	else
// 		return (-1);
// }

// int ft_isvalidparet(char *str)
// {
//     int i;
//     int open;

//     i = -1;
//     open = 0;
//     while(str[++i] && ft_is_valid_comm(str[i]))
//     {
//         if (str[i] == '(')
//             open++;
//         if (str[i] == ')')
//             open--;
//     }
//     if (!open)
//         return (1);
//     return (0);
// }
// void	ft_prt(char *str, int *a, int *b)
// {
// 	int		len;
// 	char	*s;

// 	s = NULL;
// 	len = ft_strlen(str);
// 	if (str[*b] && (str[*b] == '('))
// 	{
// 		*b += 1;
// 		while (str[*b] && str[*b] != ')'&& ft_isvalidparet(str + *b))
// 			*b += 1;
// 		if (str[*b] == ')')
// 		{
// 			s = ft_substr(str, *a + 1, *b - *a -1);
// 			*b += 1;
// 		}
// 		else if (*b == len)
// 		{
// 			// ft_free_token(lst);
// 			perror("Parenthesis Quotes error !!\n");
// 		}
// 	}
//     printf("--->  %s\n", s);
// 	if (s)
// 		free(s);
// }

// int main()
// {
//     char *s = "(abcd)kn lc(.z)";
//     int a;
//     ft_prt("sakjdfvjksvdf", 0, 0);
// }
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


int	ft_istrrchr(const char *s, int c)
{
	int	nbr;

	nbr = ft_strlen((char *)s);
	c = (char)c;
    write(1, &s[nbr], 1);
	while ((nbr != -1) && s[nbr] != c)
        nbr--;
	if (s[nbr] == c)
		return (nbr + 1);
	else
		return (-1);
}


int	ft_istrchr(const char *s, int c)
{
	int	nbr;
	int	i;

	nbr = ft_strlen((char *)s);
	c = (char)c;
	i = 0;
	while (i < nbr && s[i] != c)
        i++;
	if (s[i] == c)
		return (i);
	else
		return (-1);
}

int valid_p(char* str)
{
	int open;
	int i;

	i = -1;
	open = 0;
	while (str[++i])
	{
		if (str[i] == '(')
		{
			open++;
			valid_p(str + i +1 );
		}
		if (str[i] == ')')
			open--;
	}
	if (!open)
		return (i);
	return (-1);
}

int main()
{
	printf("----->%d\n", valid_p("(ksbdjksdf))"));
}