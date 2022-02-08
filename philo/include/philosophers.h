/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:08:41 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/08 09:10:20 by emaugale         ###   ########.fr       */
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

typedef pthread_mutex_t	t_mutex;

/*				Struc of the datas			*/

typedef struct s_info
{
	int			nbr_philo;
	int			nbr_meal;
	long long	time_start;
	int			finish;
	int			die;
	int			eat;
	int			sleep;
	int			status;
	t_mutex		*forks;
	t_mutex		*lock;

}				t_info;

/*				Struct of the philo			*/

typedef struct s_philo
{
	pthread_t			philo_id;
	t_info				*info;
	int					id;
	long long int		last_meal;
	int					meal;
	int					laps;
	int					status;
	int					laps_done;
	t_mutex				*left_fork;
	t_mutex				right_fork;
	t_mutex				lock;
	t_mutex				*lock2;
	t_mutex				aff;
}			t_philo;

/*				Prototypes			*/

long unsigned int	timestamp(void);
// void				init_mutex(t_philo *data);
int					init_mutex(t_philo *data);
void				destroy_mutex(t_philo	*data);
void				ft_info(t_info *info, char **argv);
void				ft_print(t_philo *philo, const char *msg1);
void				execute_philo(t_philo *philo);
int					philo_take_fork(t_philo *philo);
t_philo				*init(char **argv, t_info **info);
t_philo				*init_loop(char **argv, t_info **info);
int					eating(t_philo *philo);
void				philo_kill(t_philo *philo);
void				ft_run(t_philo *philo);
void				one_philo(t_philo *philo);
int					get_status(t_philo	*philo);

/*				Actions				*/
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);
int					eating(t_philo *philo);

/*				Actions				*/

/*			Prototypes utils		*/

int					ft_atoi(const char *str);
int					ft_isnum(char *str);
void				ft_usleep(long unsigned int time_in_ms, t_philo *philo);
void				ft_error(char *str);
int					ft_strlen(char *str);

/*			Prototypes utils		*/

#endif
