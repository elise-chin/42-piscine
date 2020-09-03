/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:14:02 by echin             #+#    #+#             */
/*   Updated: 2020/08/16 15:59:20 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

int	is_unique(int **res, int row, int col, int choice)
{
	int c;
	int r;

	if (row != -1)
	{
		c = -1;
		while (++c < 4)
			if (c != col && res[row][c] == choice)
			{
				return (0);
			}
	}
	if (col != -1)
	{
		r = 0;
		while (r != row && r < 4)
			if (res[r++][col] == choice)
				return (0);
	}
	return (1);
}

int	count_view_forward(int *row)
{
	int n_visible_boxes;
	int max_height;
	int i;

	n_visible_boxes = 0;
	max_height = 0;
	if (row[0])
	{
		n_visible_boxes++;
		max_height = row[0];
	}
	i = 1;
	while (i < N)
	{
		if (row[i] > row[i - 1] && row[i] > max_height)
		{
			n_visible_boxes++;
			max_height = row[i];
		}
		i++;
	}
	return (n_visible_boxes);
}

int	count_view_backward(int *row)
{
	int n_visible_boxes;
	int max_height;
	int i;

	n_visible_boxes = 0;
	max_height = 0;
	if (row[N - 1])
	{
		n_visible_boxes++;
		max_height = row[N - 1];
	}
	i = N - 2;
	while (i >= 0)
	{
		if (row[i] > row[i + 1] && row[i] > max_height)
		{
			n_visible_boxes++;
			max_height = row[i];
		}
		i--;
	}
	return (n_visible_boxes);
}

int	check_row(int *row, int left, int right)
{
	if (left == 0 && right == 0)
		return (1);
	if (left != 0 && right == 0)
		return (left == count_view_forward(row));
	if (left == 0 && right != 0)
		return (right == count_view_backward(row));
	return (left == count_view_forward(row) &&
			right == count_view_backward(row));
}

int	count_values_in_row(int *row, int value)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (++i < N)
		if (row[i] == value)
			count++;
	return (count);
}
