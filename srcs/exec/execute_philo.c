/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 03:03:51 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/03 17:47:42 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo	*philo, t_info *info)
{
	pthread_mutex_lock(&info->forks[(philo)->left_fork]);
	printf("[%lu] philo[%d] is taking left fork\n", timestamp(), philo->id);
	pthread_mutex_lock(&info->forks[(philo)->right_fork]);
	printf("[%lu] philo[%d] is taking right fork\n", timestamp(), philo->id);
	printf("[%lu] philo[%d] is eating\n", timestamp(), philo->id);
	usleep(info->eat * 1000);
	philo->last_meal = timestamp();
	philo->laps_done++;
	pthread_mutex_unlock(&info->forks[(philo)->right_fork]);
	pthread_mutex_unlock(&info->forks[(philo)->left_fork]);
}

void	thinking(t_philo *philo)
{
	printf("[%lu] philo[%d] is thinking\n", timestamp(), philo->id);
	usleep(philo->info->die - philo->info->sleep - philo->info->eat * 1000);
}

void	sleeping(t_philo *philo)
{
	printf("[%lu] philo[%d] is sleeping\n", timestamp(), philo->id);
	usleep(philo->info->sleep * 1000);
}
void	*routine(void	*philo_data)
{
	t_philo *philo;
	t_info	*info;
	
	philo = (t_philo*)philo_data;
	init_mutex(philo);
	info = (t_info*)philo->info;
	while (philo->info->done != true)
	{
		if (philo->laps_done == philo->laps)
		{
			printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa %d/%d\n", philo->laps_done, philo->laps);
			philo->info->done = true;
			return (NULL);
		}
		eating(philo, info);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void    execute_philo(t_philo *philo)
{
	int	i;

	i = -1;
	philo->info->time_start = timestamp();
	while (++i <= philo->info->nbr_philo)
	{
		if (i % 2 == 0)
		{
			
			if ((pthread_create(&(philo[i].t_id), NULL, routine, &philo[i])))
				return ;
			philo[i].last_meal = timestamp();
		}
	}
	usleep(philo->info->eat * 1000);
	i = -1;
	while (++i < philo->info->nbr_philo)
	{
		if (i % 2 == 1)
		{
			if ((pthread_create(&(philo[i].t_id), NULL, routine, &philo[i])))
				return ;
			philo[i].last_meal = timestamp();
		}
	}
	i = -1;
	while (++i < philo->info->nbr_philo)
	{
		pthread_join(philo[i].t_id, NULL);
	}
	
}
