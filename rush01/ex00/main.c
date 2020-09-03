/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:52:40 by echin             #+#    #+#             */
/*   Updated: 2020/08/16 16:12:19 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

int		main(int argc, char **argv)
{
	int *args;
	int **res;
	int i;

	if (argc != 2 || !check_string(argv[1]))
	{
		print_error();
		return (0);
	}
	res = create_tab_res();
	args = create_tab_arg(argv[1]);
	fill_first_numbers(args, res);
	if (backtrack(res, args))
		print_double_tab(res);
	else
		print_error();
	i = -1;
	while (++i < 4)
		free(res[i]);
	free(res);
	free(args);
	return (0);
}
