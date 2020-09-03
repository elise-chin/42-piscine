/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:55:25 by echin             #+#    #+#             */
/*   Updated: 2020/08/14 14:03:57 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int i;

	if (min >= max)
		return (NULL);
	i = 0;
	if ((tab = (int *)malloc((max - min) * sizeof(int))))
	{
		while (min < max)
			tab[i++] = min++;
		return (tab);
	}
	return (tab);
}
