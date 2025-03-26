/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:14:15 by adrgutie          #+#    #+#             */
/*   Updated: 2025/03/26 18:41:57 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_loop(t_philos *philos)
{
	int	name;

	name = 1;
	while (name <= philos->num_of_philo)
	{
		philos->name = name;
		philos->pids[name - 1] = fork();
		if (philos->pids[name - 1] == -1)
			kill_all_exit(philos);
		if (philos->pids[name - 1] == 0)
			//doo thing;
	}
	
}

void	philo(int argc, char *argv[])
{
	t_philos	*philos;

	philos = init_philos(argc, argv);
	if (philos->num_of_philo == 1)
	{
		philos->name = 1;
		philos->start_time = get_time_mili();
		put_message(philos, TAKE_FORK);
		usleep(philos->time_to_die * 1000);
		put_message(philos, DIE);
		exit(0);
	}
	philo_loop(philos);
}

int	main(int argc, char *argv[])
{
	if (argc > 6 || argc < 5)
		return (EXIT_FAILURE);
	if (neg_check(argc, argv) == -1)
		return (EXIT_FAILURE);
	philo(argc, argv);
	return (0);
}
