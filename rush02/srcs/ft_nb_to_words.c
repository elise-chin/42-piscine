/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_to_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:26 by echin             #+#    #+#             */
/*   Updated: 2020/08/23 21:49:33 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	units(char *nb, int len, int pos, t_cell *dict)
{
	char	*nb_to_lookup;

	if (nb[pos] == '0' && len != 1)
		return ;
	nb_to_lookup = malloc(sizeof(char) * (len + 1));
	nb_to_lookup[0] = nb[pos];
	if (pos != 0)
		ft_putchar(' ');
	ft_putstr(get_value(dict, nb_to_lookup));
	free(nb_to_lookup);
}

void	tens_power(char *nb, int len, int pos, t_cell *dict)
{
	char	*nb_to_lookup;
	int		j;

	if (len - pos < 3
			|| (nb[pos - 1] == '0' && nb[pos - 2] == '0' && nb[pos - 3] == '0'))
		return ;
	j = 0;
	nb_to_lookup = malloc(sizeof(char) * (len + 1));
	nb_to_lookup[0] = '1';
	j = -1;
	while (++j < len - pos)
		ft_strcat(nb_to_lookup, '0');
	if (pos != 0)
		ft_putchar(' ');
	ft_putstr(get_value(dict, nb_to_lookup));
}

void	hundreds(char *nb, int len, int pos, t_cell *dict)
{
	char	*nb_to_lookup;

	nb_to_lookup = malloc(sizeof(char) * (len + 1));
	if (nb[pos] == '0')
		return ;
	nb_to_lookup[0] = '\0';
	ft_strcat(nb_to_lookup, nb[pos]);
	if (pos != 0)
		ft_putchar(' ');
	ft_putstr(get_value(dict, nb_to_lookup));
	ft_putchar(' ');
	ft_putstr(get_value(dict, "100"));
}

void	tens(char *nb, int len, int pos, t_cell *dict)
{
	char *nb_to_lookup;

	nb_to_lookup = malloc(sizeof(char) * (len + 1));
	if (nb[pos] == '0')
		units(nb, len, pos + 1, dict);
	else
	{
		nb_to_lookup[0] = nb[pos];
		if (nb[pos] == '1')
			fonction1(nb_to_lookup, nb, pos);
		else
		{
			ft_strcat(nb_to_lookup, '0');
			putchar_char(pos + '0', '0', ' ');
			ft_putstr(get_value(dict, nb_to_lookup));
			putchar_char(nb[pos + 1], '0', '-');
			if (nb[pos + 1] == '0')
				return ;
			nb_to_lookup[0] = nb[pos + 1];
			nb_to_lookup[1] = '\0';
		}
		ft_putstr(get_value(dict, nb_to_lookup));
	}
}

void	write_nb(char *nb, t_cell *dict)
{
	int i;
	int len;
	int nb_grp;
	int left_over;

	i = 0;
	len = 0;
	while (nb[len])
		len++;
	nb_grp = len / 3;
	left_over = len % 3;
	if (left_over)
	{
		(left_over == 1) ? units(nb, len, i, dict) : tens(nb, len, i, dict);
		i += left_over;
		tens_power(nb, len, i, dict);
	}
	while (nb_grp-- > 0)
	{
		hundreds(nb, len, i++, dict);
		tens(nb, len, i, dict);
		i += 2;
		tens_power(nb, len, i, dict);
	}
	ft_putchar('\n');
}
