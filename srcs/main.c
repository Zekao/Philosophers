/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:50:57 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/29 04:15:45 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc < 5)
		exit(-1);
	printf("argv[1] : %s\n", argv[1]);
	philo = init(argc-1, argv + 1);
	if (!philo)
		exit(-1);
	printf("HEllo\n");
}