/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:23:19 by adrgutie          #+#    #+#             */
/*   Updated: 2025/03/26 15:07:03 by adrgutie         ###   ########.fr       */
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
			sem_post(philos->death);
			put_message(philos, DIE);
			pthread_detach(philos->ptids[philos->name - 1]);

		}
		usleep(100);
	}
}
