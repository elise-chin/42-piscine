/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:16:46 by echin             #+#    #+#             */
/*   Updated: 2020/08/16 15:55:34 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

int	satisfy_view(int **res, int *args, int row, int col)
{
	int *col_to_row;
	int r;
	int row_contains_zero;
	int col_contains_zero;

	col_to_row = (int *)malloc(4 * sizeof(int));
	if (!col_to_row)
		return (0);
	r = -1;
	while (++r < N)
		col_to_row[r] = res[r][col];
	row_contains_zero = count_values_in_row(res[row], 0) > 0 ? 1 : 0;
	col_contains_zero = count_values_in_row(col_to_row, 0) > 0 ? 1 : 0;
	if (row_contains_zero && col_contains_zero)
		return (1);
	if (!row_contains_zero && col_contains_zero)
		return (check_row(res[row], args[8 + row], args[12 + row]));
	if (row_contains_zero && !col_contains_zero)
		return (check_row(col_to_row, args[col], args[4 + col]));
	return (check_row(res[row], args[8 + row], args[12 + row]) &&
			check_row(col_to_row, args[col], args[4 + col]));
}

int	is_possible_to_place(int **res, int *args, int *position, int choice)
{
	int check_unique;
	int check_views;
	int row;
	int col;

	row = position[0];
	col = position[1];
	check_unique = is_unique(res, row, col, choice);
	check_views = satisfy_view(res, args, row, col);
	return (check_unique && check_views);
}

int	*get_empty_cell(int **res)
{
	int i;
	int j;
	int *position;

	position = (int *)malloc(2 * sizeof(int));
	if (!position)
		return (0);
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (res[i][j] == 0)
			{
				position[0] = i;
				position[1] = j;
				return (position);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	backtrack(int **res, int *args)
{
	int *empty_cell_position;
	int choice;
	int valid;
	int row;
	int col;

	empty_cell_position = get_empty_cell(res);
	if (!empty_cell_position)
		return (1);
	choice = 1;
	row = empty_cell_position[0];
	col = empty_cell_position[1];
	while (choice <= 4)
	{
		res[row][col] = choice;
		valid = is_possible_to_place(res, args, empty_cell_position, choice);
		if (valid && backtrack(res, args))
			return (1);
		else
			res[row][col] = 0;
		choice++;
	}
	return (0);
}
