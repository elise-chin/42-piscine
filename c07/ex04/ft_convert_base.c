/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:01:57 by echin             #+#    #+#             */
/*   Updated: 2020/08/19 17:10:45 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		index_of(unsigned char c, char *str);
int		is_space(unsigned char c);
int		is_base(char *str);

int		itoa_size(int nb, int base_size)
{
	int result_size;

	result_size = 0;
	if (nb <= 0)
		result_size++;
	while (nb)
	{
		result_size++;
		nb /= base_size;
	}
	return (result_size);
}

char	*itoa_base(int nb, char *base_to, int base_size)
{
	int		result_size;
	char	*result;
	int		neg;
	long	nb_copy;

	neg = 0;
	nb_copy = nb;
	result_size = itoa_size(nb, base_size);
	if (!(result = (char *)malloc((result_size + 1) * sizeof(char))))
		return (0);
	result[result_size--] = '\0';
	if (nb == 0)
		result[0] = base_to[0];
	if (nb < 0)
	{
		neg = 1;
		result[0] = '-';
		nb_copy = -nb_copy;
	}
	while (result_size >= neg)
	{
		result[result_size--] = base_to[nb_copy % base_size];
		nb_copy /= base_size;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	n;
	char	*result;
	int		base_to_size;
	int		base_from_size;
	int		sign;

	base_to_size = is_base(base_to);
	base_from_size = is_base(base_from);
	if (!(is_base(base_from)) || !base_to_size)
		return (0);
	while (*nbr && is_space(*nbr))
		nbr++;
	sign = 1;
	while (*nbr && (*nbr == '+' || *nbr == '-'))
		if (*nbr++ == '-')
			sign = -sign;
	n = 0;
	while (*nbr && index_of(*nbr, base_from) != -1)
		n = n * base_from_size + index_of(*nbr++, base_from);
	result = itoa_base((int)(sign * n), base_to, base_to_size);
	return (result);
}
