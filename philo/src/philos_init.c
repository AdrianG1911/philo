/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:58:38 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/28 18:50:25 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo_arr(t_philos *philos)
{
	t_philo	**philo_arr;
	int		i;

	philo_arr = (t_philo **)malloc(\
	philos->num_of_philo * sizeof(t_philo *) + 1);
	if (philo_arr == NULL)
		return (-1);
	memset(philo_arr, 0, philos->num_of_philo * sizeof(t_philo *) + 1);
	i = 0;
	while (i < philos->num_of_philo)
	{
		philo_arr[i] = (t_philo *)malloc(sizeof(t_philo));
		if (philo_arr[i] == NULL)
			return (free_philo_arr(philo_arr), -1);
		memset(philo_arr[i], 0, sizeof(t_philo));
		philo_arr[i]->name = i + 1;
		i++;
	}
	philos->philo_arr = philo_arr;
	i = -1;
	while (((++i) * 2) < philos->num_of_philo - 1)
		philo_arr[i * 2]->has_token = 1;
	return (1);
}

int	wrap(int i, int num_of_philo)
{
	if (i > 0)
		return (i - 1);
	else
		return (i - 1 + num_of_philo);
}

int	init_assign_forks(t_philos *philos)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	while (i < philos->num_of_philo)
	{
		fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (fork == NULL)
			return (-1);
		if (pthread_mutex_init(fork, NULL) != 0)
			return (free(fork), -1);
		philos->philo_arr[i]->l_fork = fork;
		if (philos->num_of_philo > 1)
			philos->philo_arr[wrap(i, philos->num_of_philo)]->r_fork = fork;
		fork = NULL;
		i++;
	}
	return (1);
}

int	init_pthread_ids(t_philos *philos)
{
	pthread_t	*pthread_ids;

	pthread_ids = (pthread_t *)malloc(philos->num_of_philo * sizeof(pthread_t));
	if (pthread_ids == NULL)
		return (-1);
	philos->p_ids = pthread_ids;
	return (1);
}

t_philos	*init_philos(int argc, char *argv[])
{
	t_philos	*philos;

	philos = (t_philos *)malloc(sizeof(t_philos));
	if (philos == NULL)
		return (NULL);
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
