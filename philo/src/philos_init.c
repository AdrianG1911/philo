/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:58:38 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/16 23:48:02 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo_arr_empty(t_philos *philos)
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
	return (1);
}

int	wrap(int num, int num_of_philo)
{
	if (num == -1)
		return (num + num_of_philo);
	return (num);
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
			philos->philo_arr[wrap(i - 1, philos->num_of_philo)]->r_fork = fork;
		fork = NULL;
		i++;
	}
	return (1);
}

t_philos	*init_philos(int argc, char *argv[])
{
	t_philos	*philos;

	philos = (t_philos *)malloc(sizeof(t_philos));
	if (philos == NULL)
		return (NULL);
	philos->num_of_philo = ft_get_int(argv[1]);
	philos->time_to_die = ft_get_int(argv[2]);
	philos->time_to_eat = ft_get_int(argv[3]);
	philos->time_to_sleep = ft_get_int(argv[4]);
	philos->num_of_times_must_eat = INT_MAX;
	if (argc == 6)
		philos->num_of_times_must_eat = ft_get_int(argv[5]);
	if (init_philo_arr_empty(philos) == -1)
		return (free_philos(philos), NULL);
	if (init_assign_forks(philos) == -1)
		return (free_philos(philos), NULL);
	return (philos);
}
