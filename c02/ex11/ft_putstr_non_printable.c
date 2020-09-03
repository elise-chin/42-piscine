/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:07:41 by echin             #+#    #+#             */
/*   Updated: 2020/08/09 17:40:48 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		char_is_printable(char c)
{
	if (c < ' ' || c > '~')
		return (0);
	return (1);
}

void	convert_hexa(unsigned char c)
{
	ft_putchar('\\');
	ft_putchar("0123456789abcdef"[c / 16]);
	ft_putchar("0123456789abcdef"[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (char_is_printable(str[i]))
			ft_putchar(str[i]);
		else
			convert_hexa(str[i]);
		i++;
	}
}
