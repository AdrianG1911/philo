/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:46:13 by adrgutie          #+#    #+#             */
/*   Updated: 2025/03/26 18:41:49 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>

# define DIE 0
# define TAKE_FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4

typedef struct s_philos
{
	int				name;
	long			start_time;
	long			eating_time;
	int				times_eaten;
	long			num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_of_times_must_eat;
	char			**a_t_e_sem_names;
	sem_t			**allowed_to_eat;
	sem_t			*forks;
	sem_t			*message;
	sem_t			*death;
	sem_t			*death_check;
	char			**d_e_s_sem_names;
	sem_t			**done_eating_sems;
	pid_t			*pids;
	pthread_t		*ptids;
	pthread_t		done_check_id;
	pthread_t		death_check_id;
}	t_philos;

//init
t_philos		*init_philos(int argc, char *argv[]);
//init_name
char			*get_sem_name(const char *sem_name, int num);
//utils
long			get_time_mili(void);
long			ft_atol_special(char *str);
int				neg_check(int argc, char *argv[]);
//free
void			kill_all_exit(t_philos *philos);
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
//philo_bonus_utils
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
#endif