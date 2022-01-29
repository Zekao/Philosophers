/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:50:57 by emaugale          #+#    #+#             */
/*   Updated: 2022/01/29 15:38:32 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_check_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isnum(argv[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_info	info;

	argc--;
	argv++;
	if (argc < 4 || (argc > 4 && ft_atoi(argv[4]) < 0))
	{
		write(2, "Error : Problem with arguments\n", 32);
		exit(-1);
	}
	if (argc == 4)
		philo = init(argv, &info);
	else if (argc == 5 && ft_atoi(argv[4]) > 0)
		philo = init_loop(argv, &info);
	// Si on a 5 arguemnts : on prends le 5e parametre comme le nombre de cycles.
	execute_philo(philo);
	printf("beep boop test2\n");
	exit(0);
}
