/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:12:29 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/20 15:54:20 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_or_done(t_philos *philos)
{
	if (philos->which_died != 0)
		return (-1);
	if (philos->done_eating == 1)
		return (-1);
	return (1);
}

void	death_update(t_philo *philo, t_philos *philos)
{
	pthread_mutex_lock(&(philos->death_lock));
	if (philos->which_died == 0)
		philos->which_died = philo->name;
	pthread_mutex_unlock(&(philos->death_lock));
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	death_unlock(t_philo *philo, t_philos *philos)
{
	death_update(philo, philos);
	unlock_forks(philo);
}

int	give_token_loop(t_philo *philo, t_philos *philos)
{
	int	give_index;
	int	death_check_counter;

	death_check_counter = 0;
	give_index = philo->name % philos->num_of_philo;
	while (philos->philo_arr[give_index]->has_token != 0)
	{
		if (death_check_counter % 20 == 0)
		{
			if (death_or_done(philos) == -1)
				return (-1);
		}
		death_check_counter++;
		usleep(100);
	}
	philo->has_token = 0;
	philos->philo_arr[give_index]->has_token = 1;
	return (1);
}
