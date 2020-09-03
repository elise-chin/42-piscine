/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 08:50:52 by echin             #+#    #+#             */
/*   Updated: 2020/08/12 09:07:39 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define N 10

static char	g_solution[N + 1] = "----";
static int	g_solutions_count = 0;

int	print_solution(void)
{
	int i;

	i = 0;
	while (g_solution[i])
	{
		if (g_solution[i] == '-')
			return (0);
		i++;
	}
	write(1, g_solution, N);
	write(1, "\n", 1);
	g_solutions_count++;
	return (1);
}

int	is_valid(char *g_solution, int row, int col)
{
	int r;
	int c;
	int valid;
	int	row_diff;
	int col_diff;

	c = 0;
	valid = 1;
	while (g_solution[c] && g_solution[c] != '-')
	{
		r = g_solution[c] - 48;
		if (c != col || r != row)
		{
			row_diff = row - r >= 0 ? row - r : r - row;
			col_diff = col - c >= 0 ? col - c : c - col;
			valid = valid && row_diff != col_diff && row_diff != 0 ? 1 : 0;
		}
		c++;
	}
	return (valid);
}

int	solve_ten_queens(int col)
{
	int i;
	int res;

	if (col == N)
		return (print_solution());
	i = 0;
	while (i < N)
	{
		if (is_valid(g_solution, i, col))
		{
			g_solution[col] = i + '0';
			res = solve_ten_queens(col + 1);
			g_solution[col] = '-';
		}
		i++;
	}
	return (res);
}

int	ft_ten_queens_puzzle(void)
{
	solve_ten_queens(0);
	return (g_solutions_count);
}
