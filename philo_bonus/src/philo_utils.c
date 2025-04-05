/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:02:21 by adrgutie          #+#    #+#             */
/*   Updated: 2025/04/05 22:25:07 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atol_special(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}

long	get_time_mili(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	neg_check(int argc, char *argv[])
{
	while (--argc >= 1)
	{
		if (ft_atol_special(argv[argc]) < 0)
			return (-1);
	}
	return (1);
}
