/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:31:05 by adrgutie          #+#    #+#             */
/*   Updated: 2025/03/26 17:04:56 by adrgutie         ###   ########.fr       */
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
		sem_unlink(philos->a_t_e_sem_names[i]);
		sem_unlink(philos->d_e_s_sem_names[i]);
		i++;
	}
	sem_unlink("/forks");
	sem_unlink("/message");
	sem_unlink("/death");
	sem_unlink("/death_check");
	exit(0);
}