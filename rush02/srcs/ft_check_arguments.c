/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:29:13 by echin             #+#    #+#             */
/*   Updated: 2020/08/23 22:04:54 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_positive_int(char *nb)
{
	int i;

	i = 0;
	if (nb[i] == '\0' || (nb[i] == '0' && ft_strlen(nb) > 1))
		return (0);
	while (nb[i])
	{
		if (nb[i] >= '0' && nb[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	valid_length(char *nb, t_cell *dict)
{
	int		max_len;
	int		curr_key_len;
	int		nb_len;
	t_cell	*cell;

	max_len = 0;
	nb_len = ft_strlen(nb);
	cell = dict;
	if (is_empty_list(dict))
		return (message_dict_error());
	while (cell)
	{
		curr_key_len = ft_strlen(cell->key);
		if (curr_key_len > max_len)
			max_len = curr_key_len;
		cell = cell->next;
	}
	if (nb_len > max_len + 2)
		return (message_dict_error());
	return (1);
}
