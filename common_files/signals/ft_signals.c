/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:00:23 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/23 18:04:38 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void    ft_handle_it(int sig)
{
    if (sig == SIGINT)
    {
        puts("haaaana");
    }
    else if(sig == SIGTERM)
        puts("yaaa 9tolni");
}