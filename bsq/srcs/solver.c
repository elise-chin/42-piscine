/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:31:22 by echin             #+#    #+#             */
/*   Updated: 2020/08/27 00:54:37 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "utils.h"

static int	matrix(int fd, t_char_triplet car, t_int_tuple bs, int col)
{
	char buf;
	char junk;

	if (read(fd, &buf, 1) == -1)
		return (-1);
	if (col == bs.j)
	{
		if (read(fd, &junk, 1) == -1)
			return (-1);
		if (junk != '\n')
			return (-1);
	}
	if (buf == car.obstacle)
		return (0);
	if (buf == car.blank)
		return (1);
	return (-1);
}

static void	actualize(t_sqr *square, t_int_tuple *coord, int *prev, int *dp)
{
	dp[coord->j] = ft_min(ft_min(dp[coord->j - 1], dp[coord->j]), *prev) + 1;
	if (square->size < dp[coord->j])
		square->coord = *coord;
	square->size = ft_max(square->size, dp[coord->j]);
}

t_sqr		largest_sqr(int fd, t_int_tuple bs, t_char_triplet car, int *dp)
{
	t_int_tuple	prev_tmp;
	int			test;
	t_sqr		square;
	t_int_tuple	coord;

	square = null_sqr(0);
	prev_tmp.i = 1;
	coord.i = 0;
	while (coord.i++ < bs.i)
	{
		coord.j = 0;
		while (coord.j++ < bs.j)
		{
			prev_tmp.j = dp[coord.j];
			if ((test = matrix(fd, car, bs, coord.j)) == 1)
				actualize(&square, &coord, &(prev_tmp.i), dp);
			else if (test == -1)
				return (null_sqr(-1));
			else
				dp[coord.j] = 0;
			prev_tmp.i = prev_tmp.j;
		}
	}
	return (largest_sqr_return(square, fd));
}

t_sqr		pre_solver(char *file_path, t_int_tuple bs, t_char_triplet car)
{
	int			*dp;
	int			fd;
	char		buf;
	t_sqr		square;

	if ((fd = safe_open(file_path)))
	{
		while (read(fd, &buf, 1) && buf != '\n')
			;
		if (!(dp = init_tab(bs.j)))
			return (null_sqr(0));
		square = largest_sqr(fd, bs, car, dp);
		return (square);
	}
	return (null_sqr(0));
}

int			solver(char *file_path)
{
	t_int_tuple		bs;
	t_char_triplet	car;
	t_sqr			square;
	int				fd;

	if (((fd = board_info(file_path, &bs, &car)) != -1))
	{
		if ((square = pre_solver(file_path, bs, car)).size != -1
				&& bs.i && bs.j)
		{
			fd = safe_open(file_path);
			read_line(fd);
			show_answer(fd, square, bs, car.fill);
			safe_close(fd);
			return (1);
		}
	}
	return (0);
}
