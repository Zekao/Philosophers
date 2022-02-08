/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 03:43:40 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/08 09:09:09 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	philo_dead(t_philo *philo)
{
	if ((timestamp() - philo->last_meal) >= (unsigned long)philo->info->die)
	{
		philo_kill(philo);
		pthread_mutex_unlock(philo->info->forks);
		return (1);
	}
	return (0);
}

static void	supervisor(t_philo *philo, int full, int i)
{
	while (1)
	{
		i = -1;
		full = 0;
		while (++i < philo->info->nbr_philo)
		{
			pthread_mutex_lock(philo[i].info->forks);
			if (philo[i].laps_done == philo[i].laps)
			{
				++full;
				if (full == philo->info->nbr_philo)
				{
					if (philo_dead(&philo[i]))
						return ;
					pthread_mutex_unlock(philo[i].info->forks);
					return ;
				}
			}
			if (philo_dead(&philo[i]))
				return ;
			pthread_mutex_unlock(philo[i].info->forks);
		}
		usleep(200);
	}
}

int	get_status(t_philo	*philo)
{
	pthread_mutex_lock(philo->info->forks);
	if (philo->info->status != ALIVE)
	{
		pthread_mutex_unlock(philo->info->forks);
		return (DEAD);
	}
	pthread_mutex_unlock(philo->info->forks);
	return (ALIVE);
}

void	*act(void	*philo_data)
{
	t_philo	*philo;
	t_info	*info;

	philo = philo_data;
	info = (t_info *)philo->info;
	while (get_status(philo) == ALIVE)
	{
		if (philo->laps_done == philo->laps)
			return (NULL);
		eating(philo);
		if (get_status(philo) != ALIVE)
			return (NULL);
		sleeping(philo);
		if (get_status(philo) != ALIVE)
			return (NULL);
		thinking(philo);
		if (get_status(philo) != ALIVE)
			return (NULL);
		usleep(200);
	}
	return (NULL);
}

void	execute_philo(t_philo *philo)
{
	int	i;

	i = -1;
	philo->info->time_start = timestamp();
	if (init_mutex(philo) == false)
		return ;
	if (philo->info->nbr_philo == 1)
		return (one_philo(philo));
	while (++i < philo->info->nbr_philo)
	{
		if (i % 2 == 0)
			if ((pthread_create(&(philo[i].philo_id), NULL, act, &philo[i])))
				return ;
	}
	ft_usleep(10, philo);
	i = -1;
	while (++i < philo->info->nbr_philo)
	{
		if (i % 2 == 1)
			if ((pthread_create(&(philo[i].philo_id), NULL, act, &philo[i])))
				return ;
	}
	supervisor(philo, 0xdeadbeef, 0xbabefeed);
}
