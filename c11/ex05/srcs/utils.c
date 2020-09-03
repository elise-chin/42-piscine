/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:37:01 by echin             #+#    #+#             */
/*   Updated: 2020/08/24 15:11:29 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long nb)
{
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else if (nb < 0)
	{
		if (nb == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			ft_putchar('-');
			ft_putnbr(-nb);
		}
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int		ft_index_of(char *c, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c[0])
			return (i);
	return (-1);
}

int		ft_atoi(char *str)
{
	int	i;
	int sign;
	int n;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (sign * n);
}
