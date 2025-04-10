/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:31:05 by adrgutie          #+#    #+#             */
/*   Updated: 2025/04/10 13:55:57 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_stuff(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philo)
	{
		free(philos->a_t_e_sem_names[i]);
		free(philos->d_e_s_sem_names[i]);
		free(philos->p_u_f_sem_names[i]);
		i++;
	}
	free(philos->a_t_e_sem_names);
	free(philos->d_e_s_sem_names);
	free(philos->p_u_f_sem_names);
	free(philos->pids);
	free(philos->ptids);
	free(philos->done_eating_sems);
	free(philos->picked_up_forks);
	free(philos->allowed_to_eat);
	free(philos);
}

void	post_stuff(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philo)
	{
		if (philos->done_eating_sems[i] != SEM_FAILED)
		{
			sem_post(philos->done_eating_sems[i]);
		}
		i++;
	}
	if (philos->death_check != SEM_FAILED)
		sem_post(philos->death_check);
	usleep(10000);
}

void	close_stuff(t_philos *philos, int i)
{
	sem_close(philos->allowed_to_eat[i]);
	sem_close(philos->done_eating_sems[i]);
	sem_close(philos->picked_up_forks[i]);
}

void	close_stoof(t_philos *philos)
{
	sem_close(philos->forks);
	sem_close(philos->message);
	sem_close(philos->death);
	sem_close(philos->death_check);
}

void	kill_all_exit(t_philos *philos)
{
	int	i;

	post_stuff(philos);
	i = 0;
	while (i < philos->num_of_philo)
	{
		if (philos->pids[i] >= 0)
		{
			kill(philos->pids[i], SIGTERM);
			waitpid(philos->pids[i], NULL, 0);
		}
		close_stuff(philos, i);
		sem_unlink(philos->a_t_e_sem_names[i]);
		sem_unlink(philos->d_e_s_sem_names[i]);
		sem_unlink(philos->p_u_f_sem_names[i]);
		i++;
	}
	close_stoof(philos);
	sem_unlink("/forks");
	sem_unlink("/message");
	sem_unlink("/death");
	sem_unlink("/death_check");
	free_stuff(philos);
	exit(0);
}
