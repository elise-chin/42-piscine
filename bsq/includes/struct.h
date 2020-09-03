/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 00:40:29 by abaudot           #+#    #+#             */
/*   Updated: 2020/08/27 00:46:07 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_int_tuple
{
	int i;
	int j;
}				t_int_tuple;

typedef struct	s_char_triplet
{
	char obstacle;
	char blank;
	char fill;
}				t_char_triplet;

typedef	struct	s_sqr
{
	int			size;
	t_int_tuple coord;
}				t_sqr;

#endif
