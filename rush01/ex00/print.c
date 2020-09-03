/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:03:21 by hlucie            #+#    #+#             */
/*   Updated: 2020/08/16 16:09:40 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_double_tab(int **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			ft_putchar(tab[i][j] + '0');
			ft_putchar(' ');
			j++;
		}
		ft_putchar(tab[i][j] + '0');
		ft_putchar('\n');
		i++;
	}
}

void	print_tab_int(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}
