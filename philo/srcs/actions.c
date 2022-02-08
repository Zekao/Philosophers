/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 03:15:28 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/08 03:39:27 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	sleeping(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->info->sleep, philo);
}

void	thinking(t_philo *philo)
{
	ft_print(philo, "is thinking");
}

int	eating(t_philo *philo)
{
	if (philo_take_fork(philo) == 1)
		return (1);
	ft_print(philo, "is eating");
	pthread_mutex_lock(philo->info->forks);
	philo->last_meal = timestamp();
	pthread_mutex_unlock(philo->info->forks);
	ft_usleep(philo->info->eat, philo);
	pthread_mutex_lock(philo->info->forks);
	philo->laps_done++;
	pthread_mutex_unlock(philo->info->forks);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
	return (0);
}

/*			make my philo grab forks before he start eating			*/

int	philo_take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has taken a fork");
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork))
		{
			pthread_mutex_unlock(&philo->right_fork);
			return (1);
		}
		ft_print(philo, "has taken a fork");
	}
	else
	{
		if (pthread_mutex_lock(&philo->right_fork))
		{
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		ft_print(philo, "has taken a fork");
	}
	return (0);
}

void	philo_kill(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	printf("%lu philo %d died\n", timestamp(), philo->id);
	philo->info->status = DEAD;
	pthread_mutex_unlock(&philo->lock);
}
