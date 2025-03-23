/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:58:38 by adrgutie          #+#    #+#             */
/*   Updated: 2025/03/23 15:47:45 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos	*init_philos(int argc, char *argv[])
{
	t_philos	*philos;

	philos = (t_philos *)malloc(sizeof(t_philos));
	if (philos == NULL)
		exit(1);
	memset(philos, 0, sizeof(t_philos));
	philos->num_of_philo = ft_atol_special(argv[1]);
	philos->time_to_die = ft_atol_special(argv[2]);
	philos->time_to_eat = ft_atol_special(argv[3]);
	philos->time_to_sleep = ft_atol_special(argv[4]);
	philos->num_of_times_must_eat = LONG_MAX;
	if (argc == 6)
		philos->num_of_times_must_eat = ft_atol_special(argv[5]);
	if (init_philo_arr(philos) == -1)
		return (free_philos(philos), NULL);
	if (init_assign_forks(philos) == -1)
		return (free_philos(philos), NULL);
	if (init_pthread_ids(philos) == -1)
		return (free_philos(philos), NULL);
	if (pthread_mutex_init(&(philos->death_lock), NULL) != 0)
		return (free_philos(philos), NULL);
	if (pthread_mutex_init(&(philos->message_lock), NULL) != 0)
		return (free_philos(philos), NULL);
	return (philos);
}
