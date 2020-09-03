/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:15:59 by echin             #+#    #+#             */
/*   Updated: 2020/08/05 18:06:25 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int n)
{
	int tens_digit;
	int units_digit;

	tens_digit = n / 10 + 48;
	units_digit = n % 10 + 48;
	ft_putchar(tens_digit);
	ft_putchar(units_digit);
}

void	ft_print_comb2(void)
{
	int n1;
	int n2;

	n1 = 0;
	n2 = 1;
	while (n1 < 98)
	{
		if (n1 < n2)
		{
			print_number(n1);
			ft_putchar(' ');
			print_number(n2);
			write(1, ", ", 2);
		}
		n2++;
		if (n2 > 99)
		{
			n1++;
			n2 = 0;
		}
	}
	print_number(98);
	ft_putchar(' ');
	print_number(99);
}
