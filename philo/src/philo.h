/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:46:13 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/16 15:15:55 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define DIE 0
# define TAKE_FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4

typedef struct s_philo
{
	int				name;
	long			eating_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				times_eaten;
}	t_philo;

typedef struct s_philos
{
	int				num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				num_of_times_must_eat;
	t_philo			**philo_arr;
	long			start_time;
	int				which_died;
}	t_philos;

//init
t_philos	*init_philos(int argc, char *argv[]);
//utils
long		get_time_mili(void);
int			ft_get_int(char *str);
int			neg_check(int argc, char *argv[]);
//free
void		free_philo_arr(t_philo **philo_arr);
void		free_philos(t_philos *philos);

#endif