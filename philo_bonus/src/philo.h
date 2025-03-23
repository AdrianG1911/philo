/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:46:13 by adrgutie          #+#    #+#             */
/*   Updated: 2025/03/23 16:10:04 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <semaphore.h>
# include <semaphore.h>

# define DIE 0
# define TAKE_FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4


typedef struct s_philos
{
	int				name;
	long			eating_time;
	int				times_eaten;
	int				done_eating;
	long			num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_of_times_must_eat;
	long			start_time;
	int				which_died;
	int				fork_count;
	sem_t			**allowed_to_eat;
	sem_t			*forks;
	sem_t			*message;
	sem_t			*death;
	sem_t			**done_eating_sems;
	pid_t			*pids;
	t_pthrea
}	t_philos;

//init
t_philos		*init_philos(int argc, char *argv[]);
//utils
long			get_time_mili(void);
long			ft_atol_special(char *str);
int				neg_check(int argc, char *argv[]);
//free
void			free_philo_arr(t_philo **philo_arr);
void			free_philos(t_philos *philos);
//message
void			put_message(t_philos *philos, int action);
//philo_work
void			*philo_work(void *arg);
//philo_work_utils
int				death_or_done(t_philos *philos);
int				give_token_loop(t_philo *philo, t_philos *philos);
void			death_update(t_philo *philo, t_philos *philos);
void			unlock_forks(t_philo *philo);
void			death_unlock(t_philo *philo, t_philos *philos);
#endif