/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:11:02 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/26 19:17:05 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_message(t_philo *philo, t_philos *philos, int action)
{
	long	curtime;

	pthread_mutex_lock(&(philos->message_lock));
	curtime = get_time_mili() - philos->start_time;
	if (action == DIE)
		printf("%ld %d died\n", curtime, philo->name);
	if (philos->which_died != 0)
	{
		pthread_mutex_unlock(&(philos->message_lock));
		return ;
	}
	if (action == TAKE_FORK)
		printf("%ld %d has taken a fork\n", curtime, philo->name);
	else if (action == EAT)
		printf("%ld %d is eating\n", curtime, philo->name);
	else if (action == SLEEP)
		printf("%ld %d is sleeping\n", curtime, philo->name);
	else if (action == THINK)
		printf("%ld %d is thinking\n", curtime, philo->name);
	pthread_mutex_unlock(&(philos->message_lock));
}
