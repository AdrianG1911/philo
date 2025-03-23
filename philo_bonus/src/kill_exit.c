/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:31:05 by adrgutie          #+#    #+#             */
/*   Updated: 2025/03/23 16:48:39 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_all_exit(t_philos *philos)
{
	int	i;

	i = 0;
	while(i < philos->num_of_philo)
	{
		if (philos->pids[i] >= 0)
		{
			kill(philos->pids[i], SIGTERM);
			waitpid(philos->pids[i], NULL, 0);
		}
		sem_unlink(philos->allowed_to_eat[i]);
		sem_unlink(philos->done_eating_sems[i]);
		i++;
	}
	sem_unlink(philos->forks);
	sem_unlink(philos->message);
	sem_unlink(philos->death);
	exit(0);
}