/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:50:57 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/03 17:36:50 by emaugale         ###   ########.fr       */
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
		return (0);
	}
	if (argc == 4)
		philo = init(argv, &info);
	else if (argc == 5 && ft_atoi(argv[4]) > 0)
		philo = init_loop(argv, &info);
	else
	{
		printf("Error in arguments\n");
		return (0);
	}
	while(1)
	{
		execute_philo(philo);
		printf("value of laps done : %d\n", philo->laps_done);
		if (philo->laps_done == philo->laps)
			break ;
		// if (philo->laps_done == philo->laps)
			// break ;
	}
	printf("beep boop test2\n");
}
