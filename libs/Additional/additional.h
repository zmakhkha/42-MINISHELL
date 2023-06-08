/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:21:03 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/04 05:52:44 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL_H
# define ADDITIONAL_H

# include "../includes.h"

double	ft_dtof(const char *str, int fraction);
void	ft_p2darray(char **array, int fd);
int		ft_strcmpl(const char *s1, const char *s2);
void	ft_free_2darray(void **array);

#endif