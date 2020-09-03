/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:05:03 by echin             #+#    #+#             */
/*   Updated: 2020/08/24 15:08:41 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		x;
	int		y;
	long	(*ft_tab[5])(int, int);
	int		i_op;

	if (ac != 4)
		return (0);
	x = ft_atoi(av[1]);
	y = ft_atoi(av[3]);
	i_op = ft_index_of(av[2], "+-*/%");
	ft_tab[0] = &add;
	ft_tab[1] = &substract;
	ft_tab[2] = &multiply;
	ft_tab[3] = &divide;
	ft_tab[4] = &modulo;
	if (y == 0 && i_op == 3)
		write(1, "Stop : division by zero", 23);
	else if (y == 0 && i_op == 4)
		write(1, "Stop : modulo by zero", 21);
	else if (av[2][1] == '\0' && i_op != -1)
		ft_putnbr((ft_tab[i_op])(x, y));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
