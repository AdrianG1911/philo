/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:14:15 by adrgutie          #+#    #+#             */
/*   Updated: 2025/04/10 16:29:18 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_do_stuff(t_philos *philos)
{
	put_message(philos, THINK);
	sem_wait(philos->allowed_to_eat[philos->name - 1]);
	sem_wait(philos->forks);
	put_message(philos, TAKE_FORK);
	sem_wait(philos->forks);
	put_message(philos, TAKE_FORK);
	sem_post(philos->picked_up_forks[philos->name - 1]);
	put_message(philos, EAT);
	philos->eating_time = get_time_mili() - philos->start_time;
	usleep(philos->time_to_eat * 1000);
	philos->times_eaten++;
	sem_post(philos->forks);
	sem_post(philos->forks);
	sem_wait(philos->picked_up_forks[philos->name - 1]);
	sem_post(philos->allowed_to_eat[philos->name - 1]);
	put_message(philos, SLEEP);
	usleep(philos->time_to_sleep * 1000);
}

void	child_philo(t_philos *philos)
{
	pthread_create(&(philos->ptids[philos->name - 1]), \
	NULL, check_dead_done, (void *)philos);
	while (1)
	{
		philo_do_stuff(philos);
	}
}

void	philo_loop(t_philos *philos)
{
	int	name;

	philos->start_time = get_time_mili();
	name = 1;
	while (name <= philos->num_of_philo)
	{
		philos->name = name;
		philos->pids[name - 1] = fork();
		if (philos->pids[name - 1] == -1)
			kill_all_exit(philos);
		if (philos->pids[name - 1] == 0)
			child_philo(philos);
		name++;
	}
	pthread_create(&(philos->death_check_id), \
	NULL, waiting_for_death, (void *)philos);
	pthread_create(&(philos->done_check_id), \
	NULL, waiting_for_dones, (void *)philos);
	main_waiter(philos);
	kill_all_exit(philos);
}

void	philo(int argc, char *argv[])
{
	t_philos	*philos;

	philos = init_philos(argc, argv);
	if (philos->num_of_philo == 1)
	{
		philos->name = 1;
		philos->start_time = get_time_mili();
		put_message(philos, TAKE_FORK);
		usleep(philos->time_to_die * 1000);
		put_message(philos, DIE);
		kill_all_exit(philos);
		exit(0);
	}
	philo_loop(philos);
}

int	main(int argc, char *argv[])
{
	if (argc > 6 || argc < 5)
		return (EXIT_FAILURE);
	if (neg_check(argc, argv) == -1)
		return (EXIT_FAILURE);
	philo(argc, argv);
	return (0);
}
