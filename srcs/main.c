/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:50:57 by emaugale          #+#    #+#             */
/*   Updated: 2022/01/29 04:09:51 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	argc--;
	argv++;
	if (argc < 4 || (argc > 4 && ft_atoi(argv[4]) < 0))
	{
		write(2, "Error : Problem with arguments\n", 32);
		exit(-1);
	}
	if (argc == 4)
	{
		philo = init(argv);
	}
	else if (argc == 5 && ft_atoi(argv[4]) > 0)
		philo = init_loop(argv);
	// Si on a 5 arguemnts : on prends le 5e parametre comme le nombre de cycles.
	execute_philo(philo);
	printf("beep boop test2\n");
	exit(0);	
}