/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:11:02 by adrgutie          #+#    #+#             */
/*   Updated: 2025/04/10 15:49:08 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_message(t_philos *philos, int action)
{
	long	curtime;

	sem_wait(philos->message);
	curtime = get_time_mili() - philos->start_time;
	if (action == DIE)
	{
		sem_wait(philos->death);
		printf("%ld %d died\n", curtime, philos->name);
		sem_post(philos->death_check);
		if (philos->num_of_philo > 1)
			exit(DIE);
		return ;
	}
	if (action == TAKE_FORK)
		printf("%ld %d has taken a fork\n", curtime, philos->name);
	else if (action == EAT)
		printf("%ld %d is eating\n", curtime, philos->name);
	else if (action == SLEEP)
		printf("%ld %d is sleeping\n", curtime, philos->name);
	else if (action == THINK)
		printf("%ld %d is thinking\n", curtime, philos->name);
	sem_post(philos->message);
}
