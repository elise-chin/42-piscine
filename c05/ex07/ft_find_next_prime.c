/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 08:26:06 by echin             #+#    #+#             */
/*   Updated: 2020/08/12 09:42:50 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int x;
	int upper_bound;

	if (nb <= 1)
		return (0);
	if (nb <= 3 || nb == 5)
		return (1);
	x = 6;
	upper_bound = nb / 2;
	while (x < upper_bound)
	{
		if (nb % (x - 1) == 0 || nb % (x + 1) == 0)
			return (0);
		x += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (!ft_is_prime(nb))
		nb += 2;
	return (nb);
}
