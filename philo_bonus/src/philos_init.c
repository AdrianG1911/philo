/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:58:38 by adrgutie          #+#    #+#             */
/*   Updated: 2025/04/05 22:25:03 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	setup_pids_ptids(t_philos *philos)
{
	int	i;

	philos->pids = ft_calloc(philos->num_of_philo, sizeof(pid_t));
	philos->ptids = ft_calloc(philos->num_of_philo, sizeof(pthread_t));
	if (philos->pids == NULL || philos->ptids == NULL)
		exit(1);
	i = 0;
	while (i < philos->num_of_philo)
	{
		philos->pids[i] = -1;
		philos->ptids[i] = -1;
		i++;
	}
	philos->death_check_id = -1;
	philos->done_check_id = -1;
}

void	input_argv(t_philos *philos, int argc, char *argv[])
{
	philos->num_of_philo = ft_atol_special(argv[1]);
	philos->time_to_die = ft_atol_special(argv[2]);
	philos->time_to_eat = ft_atol_special(argv[3]);
	philos->time_to_sleep = ft_atol_special(argv[4]);
	philos->num_of_times_must_eat = LONG_MAX;
	if (argc == 6)
		philos->num_of_times_must_eat = ft_atol_special(argv[5]);
}

void	open_sems(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philo)
	{
		philos->done_eating_sems[i] = \
		sem_open(philos->d_e_s_sem_names[i], O_CREAT | O_EXCL, 0666, 0);
		philos->allowed_to_eat[i] = \
		sem_open(philos->a_t_e_sem_names[i], O_CREAT | O_EXCL, 0666, 0);
		if (philos->done_eating_sems[i] == SEM_FAILED || \
			philos->allowed_to_eat[i] == SEM_FAILED)
			kill_all_exit(philos);
		i++;
	}
	philos->forks = \
	sem_open("/forks", O_CREAT | O_EXCL, 0666, philos->num_of_philo);
	philos->death = sem_open("/death", O_CREAT | O_EXCL, 0666, 1);
	philos->message = sem_open("/message", O_CREAT | O_EXCL, 0666, 1);
	philos->death_check = sem_open("/death_check", O_CREAT | O_EXCL, 0666, 0);
	if (philos->forks == SEM_FAILED || philos->death == SEM_FAILED || \
		philos->forks == SEM_FAILED || philos->forks == SEM_FAILED)
		kill_all_exit(philos);
}

void	make_sem_names(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philo)
	{
		philos->a_t_e_sem_names[i] = get_sem_name("/allowed_to_eat", i);
		philos->d_e_s_sem_names[i] = get_sem_name("/done_eating_sems", i);
		i++;
	}
}

t_philos	*init_philos(int argc, char *argv[])
{
	t_philos	*philos;

	philos = (t_philos *)ft_calloc(1, sizeof(t_philos));
	if (philos == NULL)
		exit(1);
	memset(philos, 0, sizeof(t_philos));
	input_argv(philos, argc, argv);
	setup_pids_ptids(philos);
	philos->allowed_to_eat = (sem_t **)ft_calloc(philos->num_of_philo, \
	sizeof(sem_t *));
	philos->done_eating_sems = (sem_t **)ft_calloc(philos->num_of_philo, \
	sizeof(sem_t *));
	philos->a_t_e_sem_names = (char **)ft_calloc(philos->num_of_philo, \
	sizeof(char *));
	philos->d_e_s_sem_names = (char **)ft_calloc(philos->num_of_philo, \
	sizeof(char *));
	if (philos->allowed_to_eat == NULL || philos->done_eating_sems == NULL \
		|| philos->d_e_s_sem_names == NULL || philos->a_t_e_sem_names == NULL)
		exit(1);
	make_sem_names(philos);
	open_sems(philos);
	return (philos);
}
