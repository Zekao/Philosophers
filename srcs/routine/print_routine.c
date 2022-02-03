/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 02:12:43 by emaugale          #+#    #+#             */
/*   Updated: 2022/01/30 02:12:43 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

long unsigned int timestamp(void)
{
    struct timeval	tv;
	struct timeval	ts;
	if (!ts.tv_sec)
		gettimeofday(&ts, NULL);
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec) * 1000 + (tv.tv_usec / 1000));
}