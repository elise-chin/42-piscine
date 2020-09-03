/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:23:12 by echin             #+#    #+#             */
/*   Updated: 2020/08/20 18:21:06 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *tab_map;
	int i;

	if (!(tab_map = (int *)malloc(length * sizeof(int))))
		return (0);
	i = -1;
	while (++i < length)
		tab_map[i] = f(tab[i]);
	return (tab_map);
}
