/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 03:22:59 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/08 09:40:38 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_mutex(t_philo *data)
{
	data->info->forks = malloc(sizeof(t_mutex));
	if (!data->info->forks)
		return (false);
	data->info->lock = malloc(sizeof(t_mutex));
	if (!data->info->lock)
		return (false);
	pthread_mutex_init(data->info->forks, NULL);
	pthread_mutex_init(data->info->lock, NULL);
	return (true);
}

void	destroy_mutex(t_philo	*data)
{
	free(data->info->forks);
	free(data->info->lock);
}

void	ft_info(t_info *info, char **argv)
{
	info->nbr_philo = ft_atoi(argv[0]);
	info->die = ft_atoi(argv[1]);
	info->eat = ft_atoi(argv[2]);
	info->sleep = ft_atoi(argv[3]);
	info->status = ALIVE;
	info->finish = 0;
}

t_philo	*init(char **argv, t_info **info)
{
	t_philo		*philo;
	static int	i = -1;

	ft_info(*info, argv);
	philo = malloc(sizeof(t_philo) * (ft_atoi(argv[0])));
	if (!philo)
		return (0);
	while (++i < ft_atoi(argv[0]))
	{
		philo[i].info = *info;
		philo[i].id = i;
		philo[i].laps = -1;
		philo[i].laps_done = 0;
		philo[i].last_meal = 0;
		philo[i].status = ALIVE;
		pthread_mutex_init(&philo[i].right_fork, NULL);
		pthread_mutex_init(&philo[i].lock, NULL);
		philo[(i + 1) % philo->info->nbr_philo].left_fork
			= &philo[i].right_fork;
	}
	return (philo);
}

t_philo	*init_loop(char **argv, t_info **info)
{
	t_philo		*philo;
	static int	i = -1;

	ft_info(*info, argv);
	philo = malloc(sizeof(t_philo) * (ft_atoi(argv[0])));
	if (!philo)
		return (0);
	while (++i < ft_atoi(argv[0]))
	{
		philo[i].info = *info;
		philo[i].id = i;
		philo[i].laps_done = 0;
		philo[i].last_meal = 0;
		philo[i].laps = ft_atoi(argv[4]);
		pthread_mutex_init(&philo[i].lock, NULL);
		pthread_mutex_init(&philo[i].right_fork, NULL);
		philo[(i + 1) % philo->info->nbr_philo].left_fork
			= &philo[i].right_fork;
		philo[i].status = ALIVE;
	}
	return (philo);
}
