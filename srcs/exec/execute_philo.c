/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 03:03:51 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/04 03:03:02 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long unsigned int time_in_ms)
{
	long unsigned int	start_time;

	start_time = 0;
	start_time = timestamp();
	while ((timestamp() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

void	eating(t_philo	*philo, t_info *info)
{
	t_mutex t1;
	t_mutex t2;

	pthread_mutex_init(&t1, NULL);
	pthread_mutex_init(&t2, NULL);
	pthread_mutex_lock(&info->forks[(philo)->left_fork]);
	printf("[%lu] philo[%d] is taking left fork\n", timestamp(), philo->id);
	pthread_mutex_lock(&info->forks[(philo)->right_fork]);
	printf("[%lu] philo[%d] is taking right fork\n", timestamp(), philo->id);
	printf("[%lu] philo[%d] is eating\n", timestamp(), philo->id);
	ft_usleep(info->eat);
	pthread_mutex_unlock(&info->forks[(philo)->left_fork]);
	pthread_mutex_unlock(&info->forks[(philo)->right_fork]);
	pthread_mutex_lock(&t2);
	philo->laps_done++;
	pthread_mutex_unlock(&t2);
	pthread_mutex_lock(&t1);
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&t1);
}

void	thinking(t_philo *philo)
{
	printf("[%lu] philo[%d] is thinking\n", timestamp(), philo->id);
	ft_usleep(philo->info->die - philo->info->sleep - philo->info->eat);
}

void	sleeping(t_philo *philo)
{
	// pthread_mutex_lock(&philo->info->forks[(philo)->aff_mutex]);
	printf("[%lu] philo[%d] is sleeping\n", timestamp(), philo->id);
	// pthread_mutex_unlock(&philo->info->forks[(philo)->aff_mutex]);
	ft_usleep(philo->info->sleep);
}
void	*routine(void	*philo_data)
{
	t_philo *philo;
	t_info	*info;
	
	philo = philo_data;
	info = (t_info*)philo->info;
	while (1)
	{
		if (philo->laps_done == philo->laps)
		{
			pthread_mutex_lock(philo->info->forks);
			philo->info->done = true;
			pthread_mutex_unlock(philo->info->forks);
			return (NULL);
		}
		eating(philo, philo->info);
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
	init_mutex(philo);
	while (++i < philo->info->nbr_philo)
	{
		if (i % 2 == 0)
		{
			if ((pthread_create(&(philo[i].t_id), NULL, routine, &philo[i])))
				return ;
			philo[i].last_meal = timestamp();
		}
	}
	ft_usleep(20);
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