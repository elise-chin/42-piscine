/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:01:11 by echin             #+#    #+#             */
/*   Updated: 2020/08/06 12:40:05 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_string(char *str)
{
	while (*str != '\0')
		ft_putchar(*str++);
}

void	ft_putnbr(int nb)
{
	int digit;
	int size;
	int temp;

	size = 1;
	if (nb == -2147483648)
	{
		print_string("-2147483648");
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	while (size >= 1)
	{
		digit = nb / size + '0';
		nb = nb % size;
		size /= 10;
		ft_putchar(digit);
	}
}
