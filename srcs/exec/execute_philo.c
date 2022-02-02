/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 03:03:51 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/02 23:56:15 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	eating(t_philo	*philo, t_info *info)
{
	
	pthread_mutex_lock(&info->forks[philo->left_fork]);
	printf("[%lld] philo[%d] is taking left fork", timestamp(), philo->id);
	pthread_mutex_lock(&info->forks[philo->right_fork]);
	printf("[%lld] philo[%d] is taking right fork", timestamp(), philo->id);
	printf("[%lld] philo[%d] is eating", timestamp(), philo->id);
	usleep(info->eat * 1000);
	philo->last_meal = timestamp();
	philo->laps_done++;
	pthread_mutex_unlock(&info->forks[philo->left_fork]);
	pthread_mutex_unlock(&info->forks[philo->right_fork]);
}

void	thinking(t_philo *philo)
{
	printf("[%lld] philo[%d] is thinking", timestamp(), philo->id);
}

void	sleeping(t_philo *philo)
{
	printf("[%lld] philo[%d] is sleeping", timestamp(), philo->id);
	usleep(philo->info->sleep * 1000);
}
void	*routine(void	*philo_data)
{
	t_philo *philo;
	t_info	*info;
	
	philo = (t_philo *)philo_data;
	info = (t_info *)philo->info;
	while (info->die)
	{
		if (info->finish)
			break ;
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
	while (++i < philo->id)
	{
		if (i % 2 == 0)
		{
			
			if (pthread_create(&(philo[i].t_id), NULL, routine, &philo[i]))
				return ;
			philo[i].last_meal = timestamp();
		}
	}
	usleep(philo->info->eat * 1000);
	i = -1;
	while (++i < philo->id)
	{
		if (i % 2 == 1)
		{
			if (pthread_create(&(philo[i].t_id), NULL, routine, &philo[i]))
				return ;
			philo[i].last_meal = timestamp();
		}
	}
	
}

// int main() 
// {
//   gettimeofday(&current_time, NULL);
//   printf("seconds : %ld\nmicro seconds : %ld",
// 	current_time.tv_sec, current_time.tv_usec);

//   return 0;
// }