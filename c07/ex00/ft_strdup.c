/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:51:47 by echin             #+#    #+#             */
/*   Updated: 2020/08/17 16:26:22 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*ptr;

	size = ft_strlen(src);
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr)
	{
		i = -1;
		while (++i < size)
			ptr[i] = src[i];
		ptr[i] = '\0';
	}
	return (ptr);
}
