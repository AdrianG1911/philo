/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:02:11 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/16 00:16:23 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo)
{
	if (philo == NULL)
		return ;
	if (philo->l_fork != NULL)
	{
		pthread_mutex_destroy(philo->l_fork);
		free(philo->l_fork);
		philo->l_fork = NULL;
	}
	if (philo->r_fork != NULL)
	{
		pthread_mutex_destroy(philo->r_fork);
		free(philo->r_fork);
		philo->r_fork = NULL;
	}
	free (philo);
}

void	free_philo_arr(t_philo **philo_arr)
{
	int	i;

	if (philo_arr == NULL)
		return ;
	i = 0;
	while (philo_arr[i] != NULL)
	{
		free_philo(philo_arr[i]);
		i++;
	}
	free(philo_arr);
}

void	free_philos(t_philos *philos)
{
	if (philos == NULL)
		return ;
	free_philo_arr(philos->philo_arr);
	free(philos);
}
