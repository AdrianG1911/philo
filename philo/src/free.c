/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:02:11 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/26 18:44:08 by adrgutie         ###   ########.fr       */
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
	pthread_mutex_destroy(&(philos->death_lock));
	pthread_mutex_destroy(&(philos->message_lock));
	free(philos->p_ids);
	free(philos);
}

void	free_thread_datas(t_thread_data **thread_datas)
{
	int	i;

	if (thread_datas == NULL)
		return ;
	i = 0;
	while (thread_datas[i] != NULL)
	{
		free(thread_datas[i]);
		i++;
	}
	free (thread_datas);
}
