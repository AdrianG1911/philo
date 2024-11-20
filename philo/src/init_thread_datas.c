/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread_datas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:26:49 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/18 16:38:37 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_thread_data	**init_thread_datas(t_philos *philos)
{
	t_thread_data	**thread_datas;
	int				i;

	thread_datas = (t_thread_data **)malloc((philos->num_of_philo + 1) * \
					sizeof(t_thread_data *));
	if (thread_datas == NULL)
		return (NULL);
	memset(thread_datas, 0, philos->num_of_philo);
	i = 0;
	while (i < philos->num_of_philo)
	{
		thread_datas[i] = (t_thread_data *)malloc(sizeof(t_thread_data));
		if (thread_datas[i] == NULL)
			return (free_thread_datas(thread_datas), NULL);
		thread_datas[i]->thread_id = i;
		thread_datas[i]->philos = philos;
		i++;
	}
	return (thread_datas);
}
