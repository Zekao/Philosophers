/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:20:22 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/29 04:08:01 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	set_philo(t_philo *philo, int i)
{
	if (i >= philo[0].info->nbr)
		return (1);
	if (i == 0)
		return (set_philo(philo, i + 1));
	philo[i].id = i + 1;
	philo[i].info = philo[i - 1].info;
	philo[i].leftfork = philo[i - 1].leftfork;
	philo[i].rightfork = malloc(sizeof(t_mutex));
	philo[i].finish = 0;
	philo[i].info = philo[i - 1].info;
	if (i == philo[i].info->nbr - 1)
		philo[0].leftfork = philo[i].rightfork;
	return (set_philo(philo, i + 1));
}

static int	set_info(t_info *info, int nbr_p, char **argv)
{
	info->nbr = nbr_p;
	if (pthread_mutex_init(&info->start_mutex, NULL)
		|| pthread_mutex_init(&info->sync_mutex, NULL)
		|| pthread_mutex_init(&info->start_mutex, NULL)
		|| pthread_mutex_init(&info->printer, NULL))
		return (-1);
	info->status = ALIVE;
	info->die = ft_atoi(argv[1]);
	info->eat = ft_atoi(argv[2]);
	info->sleep = ft_atoi(argv[3]);
	if (ft_isnum(argv[1]) || info->die <= 0 || info->die > INT_MAX
		|| ft_isnum(argv[2]) || info->eat <= 0 || info->eat > INT_MAX
		|| ft_isnum(argv[3]) || info->sleep <= 0 || info->sleep > INT_MAX)
		return (-1);
	return (1);
}

static int	init_first(t_philo *philo, int laps)
{
	philo->id = 1;
	philo->laps = laps;
	philo->rightfork = malloc(sizeof(t_mutex));
	if (!philo->rightfork || pthread_mutex_init(philo->rightfork, NULL)
		|| pthread_mutex_init(&philo->laps_mutex, NULL))
		return (-1);
	philo->finish = 0;
	philo->info = malloc(sizeof(t_info));
	if (!philo->info)
		return (-1);
	return (0);
}

t_philo	*init(int argc, char **argv)
{
	t_philo	*philo;
	int		nbr_p;
	int		nbr_seq;

	nbr_p = ft_atoi(argv[0]);
	if (ft_isnum(argv[0]) || nbr_p < 1 || nbr_p > 200)
		return (NULL);
	if (argc == 5)
	{
		nbr_seq = ft_atoi(argv[4]);
		if (nbr_seq < 0 || nbr_seq > INT_MAX)
			return (NULL);
	}
	else
		nbr_seq = -1;
	philo = malloc(sizeof(t_philo) * nbr_p);
	if (!philo || init_first(&philo[0], nbr_seq))
		return (NULL);
	if (printf(" OK OU PAS : %d\n", set_info(philo[0].info, nbr_p, argv)))
		return (NULL);
	set_philo(philo, 0);
	return (philo);
}
