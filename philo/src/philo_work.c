/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:18:05 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/20 00:13:59 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dying_unlock(t_philo *philo, t_philos *philos)
{
	long	time_2_death;

	time_2_death = philos->time_to_die - (get_time_mili() - \
				(philo->eating_time + philos->start_time));
	if (time_2_death <= 0)
		return (death_unlock(philo, philos), -1);
	if (time_2_death < philos->time_to_eat)
	{
		put_message(philo, philos, EAT);
		usleep(time_2_death * 1000);
		return (death_unlock(philo, philos), -1);
	}
	return (1);
}

int	token_check_loop(t_philo *philo, t_philos *philos)
{
	int	death_check_counter;

	death_check_counter = 0;
	while (philo->has_token != 1)
	{
		if (death_check_counter % 20 == 0)
		{
			if (philos->time_to_die - (get_time_mili() - \
				(philo->eating_time + philos->start_time)) <= 0)
				return (death_update(philo, philos), -1);
			if (death_or_done(philos) == -1)
				return (-1);
		}
		death_check_counter++;
		usleep(100);
	}
	pthread_mutex_lock(philo->l_fork);
	put_message(philo, philos, TAKE_FORK);
	pthread_mutex_lock(philo->r_fork);
	put_message(philo, philos, TAKE_FORK);
	return (1);
}

int	fork_loop(t_philo *philo, t_philos *philos)
{
	if (token_check_loop(philo, philos) == -1)
		return (-1);
	philo->eating_time = get_time_mili() - philos->start_time;
	if (dying_unlock(philo, philos) == -1)
		return (-1);
	if (death_or_done(philos) == -1)
		return (unlock_forks(philo), -1);
	put_message(philo, philos, EAT);
	usleep(philos->time_to_eat * 1000);
	unlock_forks(philo);
	philo->times_eaten++;
	if (give_token_loop(philo, philos) == -1)
		return (-1);
	return (1);
}

int	sleep_loop(t_philo *philo, t_philos *philos)
{
	long	time_2_death;

	if (death_or_done(philos) == -1)
		return (-1);
	time_2_death = philos->time_to_die - (get_time_mili() - \
				(philo->eating_time + philos->start_time));
	if (time_2_death <= 0)
		return (death_update(philo, philos), -1);
	if (time_2_death < philos->time_to_sleep)
	{
		put_message(philo, philos, SLEEP);
		usleep(time_2_death * 1000);
		return (death_update(philo, philos), -1);
	}
	if (death_or_done(philos) == -1)
		return (-1);
	put_message(philo, philos, SLEEP);
	usleep(philos->time_to_sleep * 1000);
	return (1);
}

void	*philo_work(void *arg)
{
	t_thread_data	*thread_data;
	t_philo			*philo;
	t_philos		*philos;

	thread_data = (t_thread_data *)arg;
	philos = thread_data->philos;
	philo = philos->philo_arr[thread_data->thread_id];
	while (1)
	{
		if (fork_loop(philo, philos) == -1)
			return ((void *)-1);
		if (sleep_loop(philo, philos) == -1)
			return ((void *)-1);
		if (death_or_done(philos) == -1)
			return ((void *)-1);
		put_message(philo, philos, THINK);
	}
}
