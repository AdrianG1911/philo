/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:02:21 by adrgutie          #+#    #+#             */
/*   Updated: 2024/11/16 14:08:09 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdig(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_get_int(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (ft_isdig == 0)
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

void	ft_putendl_fd(char *str, int fd)
{
	while (*(++str - 1) != '\0')
		write(fd, (str - 1), 1);
	write(fd, "\n", 1);
}

int	neg_check(int argc, char *argv[])
{
	while (--argc >= 1)
	{
		if (ft_get_int(argv[argc]) == -1)
			return (-1);
	}
	return (1);
}
