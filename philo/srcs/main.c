/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:50:57 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/08 19:40:32 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
		i++;
	}
	return (0);
}

int	ft_check_args(char **argv)
{
	int	i;

	i = 0;
	if (ft_atoi(argv[0]) == 0)
		return (false);
	while (argv[i])
	{
		if (ft_isnum(argv[i]) != 1)
			return (false);
		i++;
	}
	return (true);
}

int	ft_check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) >= 12)
			return (false);
		if (ft_strcmp(argv[i], "") == 0)
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_info	*info;
	int		i;

	i = -1;
	if (ft_check_argv(argv) == false)
		return (ft_error("Error : Problem with arguments\n"), 1);
	argc--;
	argv++;
	info = malloc(sizeof(t_info));
	if (!info)
		return (1);
	if (argc < 4 || (argc > 4 && ft_atoi(argv[4]) < 0)
		|| ft_check_args(argv) == false || ft_atoi(argv[0]) > 200)
		return (free(info), ft_error("Error : Problem with arguments\n"), 1);
	if (argc == 4)
		philo = init(argv, &info);
	else if (argc == 5 && ft_atoi(argv[4]) > 0 && ft_isnum(argv[4]))
		philo = init_loop(argv, &info);
	else
		return (free(info), ft_error("Error in arguments\n"), 1);
	ft_run(philo);
	free (info);
	return (0);
}

void	ft_run(t_philo *philo)
{
	int	i;

	i = 0;
	if (!philo)
		return ;
	execute_philo(philo);
	if (philo->info->nbr_philo == 1)
	{
		free(philo);
		return ;
	}
	while (i < philo->info->nbr_philo)
	{
		pthread_join(philo[i].philo_id, NULL);
		i++;
	}
	destroy_mutex(philo);
	if (philo)
		free(philo);
}
