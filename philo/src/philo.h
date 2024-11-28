/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:46:13 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/28 18:50:25 by adrgutie         ###   ########.fr       */
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
	int				has_token;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				times_eaten;
}	t_philo;

typedef struct s_philos
{
	long			num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_of_times_must_eat;
	t_philo			**philo_arr;
	long			start_time;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	message_lock;
	int				which_died;
	int				done_eating;
	pthread_t		*p_ids;
}	t_philos;

typedef struct s_thread_data
{
	int			thread_id;
	t_philos	*philos;
}	t_thread_data;

//init
t_philos		*init_philos(int argc, char *argv[]);
t_thread_data	**init_thread_datas(t_philos *philos);
//utils
long			get_time_mili(void);
long			ft_atol_special(char *str);
int				neg_check(int argc, char *argv[]);
//free
void			free_philo_arr(t_philo **philo_arr);
void			free_philos(t_philos *philos);
void			free_thread_datas(t_thread_data **thread_datas);
//message
void			put_message(t_philo *philo, t_philos *philos, int action);
//philo_work
void			*philo_work(void *arg);
//philo_work_utils
int				death_or_done(t_philos *philos);
int				give_token_loop(t_philo *philo, t_philos *philos);
void			death_update(t_philo *philo, t_philos *philos);
void			unlock_forks(t_philo *philo);
void			death_unlock(t_philo *philo, t_philos *philos);
#endif