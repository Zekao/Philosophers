/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:08:41 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/28 17:08:41 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stddef.h>
# include <pthread.h>
# include <sys/types.h>
# include <stdbool.h>

# define DEAD 0
# define ALIVE 1
# define SLEEPING 2
# define EATING 3

typedef pthread_mutex_t t_mutex;

/*				Struc of the datas			*/

typedef struct s_info
{
	int			nbr_philo;
	int			nbr;
	long long	time_start;
	int			finish;
	int			die;
	int			eat;
	int			sleep;
	int			status;
	int			done;
	t_mutex		*forks;
}				t_info;

/*				Struct of the philo			*/

typedef struct s_philo
{
	int				id;
	pthread_t		t_id;
	int				left_fork;
	int				increment_mutex;
	int				right_fork;
	int				aff_mutex;
	int				timestamp;
	int				laps;
	int				laps_done;
	long long int	last_meal;
	long long int	last_sleep;
	t_info			*info;
}			t_philo;


/*				Prototypes			*/

t_philo	*init(char **argv, t_info **info);
t_philo	*init_loop(char **argv,t_info **info);
void	execute_philo(t_philo *philo);
void	init_mutex(t_philo *data);
// void	eating(t_philo	*philo, t_info *info);
// void	thinking(t_philo *philo);
// void	sleeping(t_philo *philo);
// void	*routine(void	*philo_data);
long unsigned int timestamp(void);
// long long int	timestamp(void);

/*			Prototypes utils		*/

int	ft_atoi(const char *str);
int	ft_isnum(char *str);

/*			Prototypes utils		*/

#endif