/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 03:16:40 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/08 03:00:50 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_print(t_philo *philo, const char *msg1)
{
	pthread_mutex_lock(philo->info->forks);
	if (philo->info->status == DEAD)
	{
		pthread_mutex_unlock(philo->info->forks);
		return ;
	}
	printf("%lu %d %s\n", timestamp(), philo->id + 1, msg1);
	pthread_mutex_unlock(philo->info->forks);
}
