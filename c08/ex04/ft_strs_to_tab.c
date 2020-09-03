/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:55:11 by echin             #+#    #+#             */
/*   Updated: 2020/08/19 15:36:46 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*ptr;

	size = ft_strlen(src);
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr)
	{
		i = -1;
		while (++i < size)
			ptr[i] = src[i];
		ptr[i] = '\0';
	}
	return (ptr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			w;

	tab = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab)
		return (0);
	w = 0;
	while (w < ac)
	{
		tab[w].size = ft_strlen(av[w]);
		tab[w].str = av[w];
		tab[w].copy = ft_strdup(av[w]);
		w++;
	}
	tab[w].size = 0;
	tab[w].str = 0;
	tab[w].copy = 0;
	return (tab);
}
