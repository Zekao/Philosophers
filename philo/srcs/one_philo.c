/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:48:14 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/08 08:49:15 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	one_philo(t_philo *philo)
{
	if (philo->info->nbr_philo == 1)
	{
		ft_print(philo, "has taken a fork");
		ft_usleep(philo->info->die, philo);
		philo_kill(philo);
		destroy_mutex(philo);
	}
}
