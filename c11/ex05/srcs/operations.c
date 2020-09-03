/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 09:49:37 by echin             #+#    #+#             */
/*   Updated: 2020/08/24 15:08:49 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

long	add(int x, int y)
{
	return (x + y);
}

long	substract(int x, int y)
{
	return (x - y);
}

long	multiply(int x, int y)
{
	return (x * y);
}

long	divide(int x, int y)
{
	return (x / y);
}

long	modulo(int x, int y)
{
	return (x % y);
}
