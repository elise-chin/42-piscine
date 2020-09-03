/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeconin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:10:38 by ldeconin          #+#    #+#             */
/*   Updated: 2020/08/16 15:54:22 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

void	fill_first_numbers(int *tab, int **res)
{
	unsigned int index_tab;

	index_tab = 0;
	while (index_tab < 16)
	{
		if (tab[index_tab] == 1)
		{
			fill_first_nb_one(res, index_tab);
		}
		if (tab[index_tab] == 4)
		{
			fill_first_nb_four(res, index_tab);
		}
		index_tab++;
	}
}

void	fill_first_nb_one(int **res, int index_tab)
{
	if (index_tab < 8)
		res[index_tab > 3 ? 3 : 0][index_tab % 4] = 4;
	else
		res[index_tab % 4][index_tab > 11 ? 3 : 0] = 4;
}

void	fill_first_nb_four(int **res, int index_tab)
{
	if (index_tab < 8)
	{
		res[index_tab > 3 ? 3 : 0][index_tab % 4] = 1;
		res[index_tab > 3 ? 2 : 1][index_tab % 4] = 2;
		res[index_tab > 3 ? 1 : 2][index_tab % 4] = 3;
		res[index_tab > 3 ? 0 : 3][index_tab % 4] = 4;
	}
	else
	{
		res[index_tab % 4][index_tab > 11 ? 3 : 0] = 1;
		res[index_tab % 4][index_tab > 11 ? 2 : 1] = 2;
		res[index_tab % 4][index_tab > 11 ? 1 : 2] = 3;
		res[index_tab % 4][index_tab > 11 ? 0 : 3] = 4;
	}
}

int		*create_tab_arg(char *str)
{
	int *tab;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(int) * 16)))
		exit(0);
	while (i < 31)
	{
		tab[j] = str[i] - '0';
		j++;
		i += 2;
	}
	return (tab);
}

int		**create_tab_res(void)
{
	int **res;
	int i;
	int j;

	i = 0;
	if (!(res = (int **)malloc(4 * sizeof(int *))))
		return (0);
	while (i < 4)
	{
		res[i] = malloc(4 * sizeof(int));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[i][j] = 0;
			j++;
		}
		i++;
	}
	return (res);
}
