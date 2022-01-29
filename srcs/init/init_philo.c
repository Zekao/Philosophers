/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 03:05:33 by emaugale          #+#    #+#             */
/*   Updated: 2022/01/29 06:23:53 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

t_philo *init(char **argv)
{
	t_philo		*philo;
	static int	i = -1;

	philo = malloc(sizeof(t_philo) * (ft_atoi(argv[0])));
	if (!philo)
	{
		return (0);
	}
	while (++i < ft_atoi(argv[0]))
	{
		philo->id = i;
		// philo->info->die = ft_atoi(argv[1]);
		// philo->info->eat = ft_atoi(argv[2]);
		// philo->info->sleep = ft_atoi(argv[3]);
		philo->die = ft_atoi(argv[1]);
		philo->eat = ft_atoi(argv[2]);
		philo->sleep = ft_atoi(argv[3]);
		philo->laps = -1;
		philo = philo->next;
	}
	printf("number of philo : %d\n", i);
	return (philo);
}

/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if i have 5 args, i add a new info about the laps, if i have 4 args, i define laps to -1
		-1 because it will be my value to said : ok there is no limit of laps given by the user
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

t_philo	*init_loop(char **argv)
{
	t_philo	*philo;
	
	static int	i = 0;
	philo = malloc(sizeof(t_philo) * (ft_atoi(argv[0])));
	if (!philo)
	{
		return (0);
	}
	while (++i < ft_atoi(argv[0]))
	{
		philo->id = i;
		philo->info->die = ft_atoi(argv[1]);
		philo->info->eat = ft_atoi(argv[2]);
		philo->info->sleep = ft_atoi(argv[3]);
		philo->laps = ft_atoi(argv[4]);
	}
	printf("number of philo : %d\n", i);
	return (philo);
}


