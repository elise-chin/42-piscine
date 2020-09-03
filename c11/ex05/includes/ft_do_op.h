/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:06:49 by echin             #+#    #+#             */
/*   Updated: 2020/08/24 15:14:04 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DO_OP_H
# define FT_DO_OP_H

# include <unistd.h>
# include <stdlib.h>

long	add(int x, int y);
long	substract(int x, int y);
long	divide(int x, int y);
long	multiply(int x, int y);
long	modulo(int x, int y);
void	ft_putchar(char c);
void	ft_putnbr(long nb);
int		ft_index_of(char *c, char *str);
int		ft_atoi(char *str);

#endif
