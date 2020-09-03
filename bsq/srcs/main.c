/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 20:37:53 by echin             #+#    #+#             */
/*   Updated: 2020/08/26 23:08:50 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "utils.h"

int	main(int ac, char **av)
{
	char *filename;

	if (ac == 1)
	{
		if (!(filename = stdin_to_file()) || !(solver(filename)))
			write(1, "map error\n", 10);
	}
	while (--ac)
	{
		if (!solver(*(++av)))
			write(1, "map error\n", 10);
		if (ac > 1)
			write(1, "\n", 1);
	}
	return (0);
}
