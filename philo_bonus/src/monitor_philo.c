/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:23:19 by adrgutie          #+#    #+#             */
/*   Updated: 2025/04/05 22:52:40 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_dead_done(void *arg)
{
	long		curtime;
	t_philos	*philos;

	philos = (t_philos *)arg;
	while (1)
	{
		curtime = get_time_mili() - philos->start_time;
		if (curtime - philos->eating_time >= philos->time_to_die)
		{
			put_message(philos, DIE);
			pthread_detach(philos->ptids[philos->name - 1]);
		}
		if (philos->times_eaten >= philos->num_of_times_must_eat \
			&& philos->done_eating_flag == 0)
		{
			philos->done_eating_flag = 1;
			sem_post(philos->done_eating_sems[philos->name - 1]);
		}
		usleep(100);
	}
	return (NULL);
}

void	*waiting_for_dones(void *arg)
{
	t_philos	*philos;
	int			i;

	philos = (t_philos *)arg;
	i = 0;
	while (i < philos->num_of_philo)
	{
		sem_wait(philos->done_eating_sems[i]);
		i++;
	}
	kill_all_exit(philos);
	return (NULL);
}

void	*waiting_for_death(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	sem_wait(philos->death_check);
	kill_all_exit(philos);
	return (NULL);
}

int	wrap(int num, t_philos *philos)
{
	int	philonum;

	philonum = philos->num_of_philo;
	if (num >= philonum)
		num = num - philos->num_of_philo;
	return (num);
}

void	main_waiter(t_philos *philos)
{
	int	allowed_start;
	int	allowed_num;
	int	i;

	allowed_start = 0;
	allowed_num = philos->num_of_philo / 2;
	while (1)
	{
		allowed_start = wrap(allowed_start, philos);
		i = -1;
		while (++i < allowed_num)
			sem_post(philos->allowed_to_eat[wrap(allowed_start + i, philos)]);
		usleep(900 * philos->time_to_eat);
		i = -1;
		while (++i < allowed_num)
			sem_wait(philos->allowed_to_eat[wrap(allowed_start + i, philos)]);
		allowed_start += i;
	}
}
