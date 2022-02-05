/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:50:57 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/05 04:41:48 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_check_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isnum(argv[i]) != 1)
			return (false);
		i++;
	}
	return (true);
}

void	exit_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->nbr_philo)
	{
		pthread_join(philo[i].t_id, NULL);
	}
	printf("FINI DE JOIN\n");
}
int     main(int argc, char **argv)
{
        t_philo *philo;
        t_info  *info;
        int             i;
        i = -1;

        argc--;
        argv++;
        info = malloc(sizeof(t_info));
        if (!info)
                return (1);
        if (argc < 4 || (argc > 4 && ft_atoi(argv[4]) < 0) || ft_check_args(argv) == false)
        {
                write(2, "Error : Problem with arguments\n", 32);
                return (1);
        }
        if (argc == 4)
                philo = init(argv, &info);
        else if (argc == 5 && ft_atoi(argv[4]) > 0 && ft_isnum(argv[4]))
                philo = init_loop(argv, &info);
        else
        {
                printf("Error in arguments\n");
                return (1);
        }
        execute_philo(philo);
        while (1)
        {
                if (philo->laps_done == philo->laps)
                        break ;
                while (i++ < philo->info->nbr_philo && philo[i].info->status != DEAD && philo->laps_done != philo->laps)
                {
                        if (timestamp() - philo[i].last_meal > (unsigned long long)philo[i].info->die)
                        {
                                printf("[%llu] philo[%d] died\n", timestamp() - philo[i].info->time_start, philo[i].id);
								return (1);
                        }
               			i = -1;
                }
                if (philo[i].info->status == DEAD)
                        break ;
                i = -1;
        }
		i = -1;
	exit_philo(philo);
	printf("All philosophers eaten enough\n");
    return (0);
}