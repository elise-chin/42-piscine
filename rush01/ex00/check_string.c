/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:58:24 by hlucie            #+#    #+#             */
/*   Updated: 2020/08/16 15:02:34 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		check_string(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) != 31)
		return (0);
	while (i < 31)
	{
		if ((str[i] > '4' || str[i] < '1') ||
				(str[i + 1] != ' ' && str[i + 1] != '\0'))
			return (0);
		i += 2;
	}
	return (1);
}
