/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:31:10 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/16 15:16:30 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_message(t_philos *philos, t_philo *philo, int action)
{
	printf("%ld ", get_time_mili());
	if (action == DIE)
		printf("%d died\n", philos->which_died);
	else if (action == TAKE_FORK)
		printf("%d has taken a fork\n", philo->name);
	else if (action == EAT)
		printf("%d is eating\n", philo->name);
	else if (action == SLEEP)
		printf("%d is sleeping\n", philo->name);
	else if (action == THINK)
		printf("%d is thinking\n", philo->name);
}
