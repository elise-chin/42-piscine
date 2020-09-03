/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 08:55:29 by echin             #+#    #+#             */
/*   Updated: 2020/08/14 11:22:55 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (0);
	tab = (int *)malloc((max - min) * sizeof(int));
	if (!tab)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
		tab[i++] = min++;
	*range = tab;
	return (i);
}
