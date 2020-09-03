/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 20:06:31 by echin             #+#    #+#             */
/*   Updated: 2020/08/23 20:47:28 by wel-mahj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_cell	*create_cell(char *key, char *value)
{
	t_cell *cell;

	if (!(cell = malloc(sizeof(t_cell))))
		return (NULL);
	cell->key = key;
	cell->value = value;
	cell->next = NULL;
	return (cell);
}

t_cell	*empty_list(void)
{
	return (NULL);
}

int		is_empty_list(t_cell *l)
{
	return (l == NULL);
}

t_cell	*add_at(t_cell *l, char *key, char *value, int pos)
{
	t_cell	*prev;
	t_cell	*curr;
	t_cell	*cell;
	int		i;

	prev = l;
	curr = l;
	cell = create_cell(key, value);
	if (is_empty_list(l))
		return (cell);
	if (pos == 0)
	{
		cell->next = l;
		return (cell);
	}
	i = -1;
	while (++i < pos)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = cell;
	cell->next = curr;
	return (l);
}

char	*get_value(t_cell *l, char *key)
{
	int i;

	if (is_empty_list(l))
	{
		message_dict_error();
		return (NULL);
	}
	i = -1;
	while (l)
	{
		if (!ft_strcmp(key, l->key))
			return (l->value);
		l = l->next;
	}
	message_dict_error();
	return (NULL);
}
