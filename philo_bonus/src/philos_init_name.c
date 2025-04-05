/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:14:29 by adrgutie          #+#    #+#             */
/*   Updated: 2025/04/05 22:29:01 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	numlen(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_sp(int num)
{
	char	*cnum;
	int		nlen;

	nlen = numlen(num);
	cnum = (char *)ft_calloc(nlen + 1, sizeof(char));
	if (cnum == NULL)
		exit(1);
	while (nlen > 0)
	{
		cnum[nlen - 1] = (num % 10) + '0';
		nlen--;
		num = num / 10;
	}
	return (cnum);
}

char	*get_sem_name(char *sem_name, int num)
{
	char	*cnum;
	char	*combo_name;
	int		cnumlen;
	int		snamelen;

	cnum = ft_itoa_sp(num);
	cnumlen = ft_strlen(cnum);
	snamelen = ft_strlen(sem_name);
	combo_name = (char *)ft_calloc(cnumlen + snamelen + 1, sizeof(char));
	if (combo_name == NULL)
		exit(1);
	ft_memcpy(combo_name, sem_name, snamelen + 1);
	ft_memcpy(combo_name + snamelen, cnum, cnumlen + 1);
	free(cnum);
	return (combo_name);
}
