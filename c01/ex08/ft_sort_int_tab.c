/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:52:19 by echin             #+#    #+#             */
/*   Updated: 2020/08/06 18:27:07 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

int		partition(int *tab, int begin, int end)
{
	int pivot;
	int i;
	int j;

	pivot = tab[end];
	i = begin - 1;
	j = begin;
	while (j < end)
	{
		if (tab[j] < pivot)
		{
			i++;
			ft_swap(&tab[i], &tab[j]);
		}
		j++;
	}
	ft_swap(&tab[i + 1], &tab[end]);
	return (i + 1);
}

void	quick_sort(int *tab, int begin, int end)
{
	int	pivot_index;

	if (begin < end)
	{
		pivot_index = partition(tab, begin, end);
		quick_sort(tab, begin, pivot_index - 1);
		quick_sort(tab, pivot_index + 1, end);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	quick_sort(tab, 0, size - 1);
}
