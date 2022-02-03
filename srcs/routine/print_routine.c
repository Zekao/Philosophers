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

void	print_routine(t_philo *philo)
{
	struct timeval current_time;
	struct timeval start_time;
	static long int	start_time_v = 0; 
	(void)philo;

	gettimeofday(&start_time, NULL);
	if (start_time_v == 0)
		start_time_v = start_time.tv_usec;
	gettimeofday(&current_time, NULL);
	sleep(1);
	while (current_time.tv_sec - start_time.tv_sec < 10)
	{
		printf("[%ld], philo[%d] is %s\n", current_time.tv_usec - start_time_v, 1, "doing something");
		gettimeofday(&current_time, NULL);
		sleep(1);
	}
}

long unsigned int timestamp(void)
{
    struct timeval	tv;
	struct timeval	ts;
	if (!ts.tv_sec)
		gettimeofday(&ts, NULL);
    gettimeofday(&tv, NULL);
    // return ((tv.tv_sec) * 1000 + (tv.tv_usec / 1000));
    return ((tv.tv_sec) * 1000 + (tv.tv_usec / 1000));
}