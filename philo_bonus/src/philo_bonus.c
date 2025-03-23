/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:14:15 by adrgutie          #+#    #+#             */
/*   Updated: 2025/03/23 15:54:02 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(int argc, char *argv[])
{
	t_philos	*philos;

	philos = init_philos(argc, argv);
	if (philos == NULL)
		exit(1);
	if (philos->num_of_philo == 1)
	{
		philos->name = 1;
		philos->start_time = get_time_mili();
		put_message(philos, TAKE_FORK);
		usleep(philos->time_to_die * 1000);
		put_message(philos, DIE);
		return (free_philos(philos), EXIT_SUCCESS);
	}
	return (philo_loop(philos));
}

int	main(int argc, char *argv[])
{
	if (argc > 6 || argc < 5)
		return (EXIT_FAILURE);
	if (neg_check(argc, argv) == -1)
		return (EXIT_FAILURE);
	return (philo(argc, argv));
}
