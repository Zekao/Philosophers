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
# include <time.h>
# include <limits.h>
# include <stddef.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/types.h>

# define DEAD 0
# define ALIVE 1
# define SLEEPING 2
# define EATING 3

typedef pthread_mutex_t t_mutex;

/*				Struc of the datas			*/

typedef struct s_info
{
	int		nbr;
	t_mutex	sync_mutex;
	t_mutex	start_mutex;
	t_mutex	printer;
	time_t	time_start;
	time_t	die;
	time_t	eat;
	time_t	sleep;
	int		status;
}				t_info;

/*				Struct of the philo			*/

typedef struct s_philo
{
	int		id;
	int		laps;
	int		finish;
	t_mutex	laps_mutex;
	t_mutex	*leftfork;
	t_mutex	*rightfork;
	time_t	last_meal;
	t_info	*info;
}			t_philo;


/*				Prototypes			*/

t_philo	*init(int argc, char **argv);

/*			Prototypes utils		*/

int	ft_atoi(const char *str);
int	ft_isnum(char *str);

/*			Prototypes utils		*/

#endif