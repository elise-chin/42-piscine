/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 20:32:42 by echin             #+#    #+#             */
/*   Updated: 2020/08/26 23:40:15 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int				ft_min(int x, int y)
{
	return (x < y ? x : y);
}

int				ft_max(int x, int y)
{
	return (x < y ? y : x);
}

int				safe_open(char *path)
{
	int fd;

	fd = 0;
	if ((fd = open(path, O_RDONLY)) >= 0)
		return (fd);
	else
		return (0);
}

int				safe_close(int fd)
{
	if (!close(fd))
		return (1);
	else
		return (0);
}

int				ft_atoi(char *str, int size)
{
	int	i;
	int sign;
	int n;

	i = 0;
	sign = 1;
	n = 0;
	while (i < size && ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' '))
		i++;
	while (i < size && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (i < size && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (sign * n);
}
