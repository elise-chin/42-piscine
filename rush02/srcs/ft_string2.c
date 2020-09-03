/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 19:13:54 by echin             #+#    #+#             */
/*   Updated: 2020/08/23 22:14:41 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_split(char *str, int size, char *key, char *value)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (str[i] >= '0' && str[i] <= '9')
			key[j++] = str[i++];
		key[j] = '\0';
		while (str[i] == ' ')
			i++;
		if (str[i] == ':')
			i++;
		while (str[i] == ' ')
			i++;
		j = 0;
		while (str[i] >= 32 && str[i] <= 126 && i < size)
		{
			value[j++] = str[i++];
		}
		value[j] = '\0';
		return (1);
	}
	return (0);
}

int		ft_is_empty_line(char *str)
{
	int i;

	i = 0;
	while ((str[i] == '\f') || (str[i] == '\t')
	|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == ' '))
		i++;
	if (str[i] == '\n')
		return (1);
	else
		return (0);
}
