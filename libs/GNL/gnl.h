/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:58:44 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 18:22:13 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "../libc_function/lib_c.h"
# include <stddef.h> /* typedef : size_t */

/*  *************** GET_NEXT_LINE ************** */
char	*get_next_line_bonus(int fd);
char	*get_next_line(int fd);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);

#endif
