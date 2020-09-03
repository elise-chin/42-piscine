/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:58:23 by abaudot           #+#    #+#             */
/*   Updated: 2020/08/27 10:34:46 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "utils.h"

int		duplicates(char a, char b, char c)
{
	if (a == b || b == c || a == c)
		return (1);
	return (0);
}

void	set_triplet(t_char_triplet *car, char *line, int size)
{
	car->fill = line[size - 1];
	car->obstacle = line[size - 2];
	car->blank = line[size - 3];
}

int		*init_tab(int size)
{
	int *tab;
	int i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * (size + 1))))
		return (0);
	tab[0] = 0;
	while (++i <= size)
		tab[i] = 0;
	return (tab);
}

t_sqr	null_sqr(int size)
{
	t_sqr ans;

	ans.size = size;
	ans.coord.i = 0;
	ans.coord.j = 0;
	return (ans);
}

t_sqr	largest_sqr_return(t_sqr sqr, int fd)
{
	char c;

	if (read(fd, &c, 1) > 0)
		return (null_sqr(-1));
	safe_close(fd);
	return (sqr);
}
