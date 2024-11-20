/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:14:15 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/20 15:33:59 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_join(int i, t_philos *philos)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_join(philos->p_ids[j], NULL);
		j++;
	}
}

void	death_done_monitor_loop(t_philos *philos)
{
	long	num_done;

	while (1)
	{
		if (philos->which_died != 0)
		{
			put_message(philos->philo_arr[philos->which_died - 1], philos, DIE);
			return ;
		}
		num_done = 0;
		while (num_done < philos->num_of_philo)
		{
			if (philos->philo_arr[num_done]->times_eaten < \
			philos->num_of_times_must_eat)
				break ;
			num_done++;
		}
		if (num_done == philos->num_of_philo)
		{
			philos->done_eating = 1;
			return ;
		}
		usleep(100);
	}
}

int	philo_loop(t_philos *philos)
{
	int				i;
	t_thread_data	**thread_datas;

	thread_datas = init_thread_datas(philos);
	if (thread_datas == NULL)
		return (free(philos), -1);
	i = 0;
	philos->start_time = get_time_mili();
	while (i < philos->num_of_philo)
	{
		if (pthread_create(&(philos->p_ids[i]), NULL, philo_work, \
		(void *)thread_datas[i]) == -1)
			break ;
		i++;
	}
	death_done_monitor_loop(philos);
	philo_join(i, philos);
	free_thread_datas(thread_datas);
	if (i < philos->num_of_philo)
		return (free_philos(philos), 1);
	return (free_philos(philos), 0);
}

int	philo(int argc, char *argv[])
{
	t_philos	*philos;

	philos = init_philos(argc, argv);
	if (philos == NULL)
		return (-1);
	if (philos->num_of_philo == 1)
	{
		philos->start_time = get_time_mili();
		put_message(philos->philo_arr[0], philos, TAKE_FORK);
		usleep(philos->time_to_die * 1000);
		put_message(philos->philo_arr[0], philos, DIE);
		return (0);
	}
	return (philo_loop(philos));
}

int	main(int argc, char *argv[])
{
	if (argc > 6 || argc < 5)
		return (1);
	if (neg_check(argc, argv) == -1)
		return (1);
	return (philo(argc, argv));
}
