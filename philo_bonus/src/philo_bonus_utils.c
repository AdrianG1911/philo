/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:32:05 by adrgutie          #+#    #+#             */
/*   Updated: 2025/04/10 16:12:34 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_ptr;

	b_ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_ptr[i] = c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb && SIZE_MAX / nmemb < size)
	{
		return (NULL);
	}
	p = malloc(nmemb * size);
	if (p)
		ft_memset(p, 0, nmemb * size);
	return (p);
}

void	post_loop(t_philos *philos)
{
	int	i;
	int	philnum;

	i = 0;
	philnum = philos->num_of_philo;
	while (i < philnum)
	{
		sem_post(philos->allowed_to_eat[i]);
		sem_post(philos->picked_up_forks[i]);
		i++;
	}
}
