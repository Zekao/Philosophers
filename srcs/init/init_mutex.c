/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:48:10 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/02 22:48:10 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	init_mutex(t_philo *data)
{
	int	i;

	i = -1;
	data->info->forks = malloc(sizeof(t_mutex) * (data->info->nbr_philo));
	if (!data->info->forks)
		return ;
	while (++i < data->info->nbr_philo)
	{
		if ((pthread_mutex_init(&data->info->forks[i], NULL)))
			return ;
	}
	pthread_mutex_init(&data->info->aff, NULL);
}