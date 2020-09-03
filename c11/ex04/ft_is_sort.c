/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:51:42 by echin             #+#    #+#             */
/*   Updated: 2020/08/24 12:52:59 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_same_sign(int x, int y)
{
	if ((x <= 0 && y <= 0) || (x >= 0 && y >= 0))
		return (1);
	return (0);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int sign;

	if (length == 0 || length == 1)
		return (1);
	sign = f(tab[0], tab[1]) < 0 ? -1 : 1;
	i = 1;
	while (++i < length)
		if (!is_same_sign(sign, f(tab[i - 1], tab[i])))
			return (0);
	return (1);
}
