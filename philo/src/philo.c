/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:14:15 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/16 15:50:15 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(int argc, char *argv[])
{
	t_philos	*philos;

	philos = init_philos(argc, argv);
	if (philos == NULL)
		return (-1);
	philos->start_time = get_time_mili();
	
}

int	main(int argc, char *argv[])
{
	if (argc > 6 || argc < 5)
		return (1);
	if (neg_check(argc, argv) == -1)
		return (1);
}
