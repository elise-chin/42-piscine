/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:12:45 by echin             #+#    #+#             */
/*   Updated: 2020/08/06 16:51:22 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int index;

	index = 0;
	while (index < size / 2)
	{
		ft_swap(&tab[index], &tab[size - 1 - index]);
		index++;
	}
}
