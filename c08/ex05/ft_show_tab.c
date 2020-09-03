/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:01:30 by echin             #+#    #+#             */
/*   Updated: 2020/08/19 15:38:04 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, &(*str++), 1);
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + '0');
	else if (nb > 0)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		if (nb == -2147483648)
			ft_putstr("-2147483648");
		else
		{
			write(1, "-", 1);
			ft_putnbr(-nb);
		}
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	w;

	w = 0;
	while (par[w].str)
	{
		ft_putstr(par[w].str);
		ft_putnbr(par[w].size);
		write(1, "\n", 1);
		ft_putstr(par[w].copy);
		w++;
	}
}
