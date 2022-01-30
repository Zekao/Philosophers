/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 03:03:51 by emaugale          #+#    #+#             */
/*   Updated: 2022/01/30 02:16:40 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void    execute_philo(t_philo *philo)
{
	print_routine(philo);
	(void)philo; 
}

// int main() 
// {
//   gettimeofday(&current_time, NULL);
//   printf("seconds : %ld\nmicro seconds : %ld",
// 	current_time.tv_sec, current_time.tv_usec);

//   return 0;
// }