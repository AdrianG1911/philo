/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:46:13 by adrgutie          #+#    #+#             */
/*   Updated: 2025/04/10 12:54:21 by adrgutie         ###   ########.fr       */
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
# include <sys/wait.h>

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
	int				done_eating_flag;
	int				dead_flag;
	long			num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_of_times_must_eat;
	char			**a_t_e_sem_names;
	sem_t			**allowed_to_eat;
	char			**p_u_f_sem_names;
	sem_t			**picked_up_forks;
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
char			*get_sem_name(char *sem_name, int num);
//utils
long			get_time_mili(void);
long			ft_atol_special(char *str);
int				neg_check(int argc, char *argv[]);
//free
void			kill_all_exit(t_philos *philos);
void			free_stuff(t_philos *philos);
//message
void			put_message(t_philos *philos, int action);
//monitor_philo
void			*check_dead_done(void *arg);
void			main_waiter(t_philos *philos);
void			*waiting_for_death(void *arg);
void			*waiting_for_dones(void *arg);
//philo_bonus_utils
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
#endif