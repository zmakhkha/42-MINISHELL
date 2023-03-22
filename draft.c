/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:02:26 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/22 17:33:52 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<libc.h>

// char	*ft_join_free(char *s1, char *s2)
// {
// 	size_t		l1;
// 	size_t		l2;
// 	int			i;
// 	char		*res;
// 	res = NULL;
// 	if (s1 && s2)
// 	{
// 		l1 = strlen(s1);
// 		l2 = strlen(s2);
// 		res = (char *)malloc(l1 + l2 + 1);
// 		i = -1;
// 		while (++i < (int)l1)
// 			res[i] = s1[i];
// 		i = -1;
// 		while (++i < (int)l2)
// 			res[l1 + i] = s2[i];
// 		res[l1 + i] = 0;
// 	}
// 	return (res);
// }
// char	*ft_heredoc()
// {
// 	char	*hdoc;
// 	char	*star;

// 	star = NULL;
// 	hdoc = calloc(1, 1);
// 	while (1)
// 	{
// 		star = readline("> ");
// 		if (star == NULL)
// 			break ;
// 		ft_join_free(hdoc, star);
// 	}
// 	return (hdoc);
// }

// int main()
// {
//     printf("%s", ft_heredoc());
// }