/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_to_words2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 21:07:37 by echin             #+#    #+#             */
/*   Updated: 2020/08/23 21:18:03 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	putchar_char(char a, char b, char c)
{
	if (a != b)
		ft_putchar(c);
}

void	fonction1(char *nb_to_lookup, char *nb, int pos)
{
	ft_strcat(nb_to_lookup, nb[pos + 1]);
	putchar_char(pos + '0', '0', ' ');
}
