/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 08:57:04 by echin             #+#    #+#             */
/*   Updated: 2020/08/14 14:18:36 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
char	*malloc_str(int size, char **strs, char *sep)
{
	char	*str;
	int		str_size;
	int		i;

	str_size = 0;
	i = 0;
	while (i < size)
		str_size += ft_strlen(strs[i++]);
	str_size += ft_strlen(sep) * (size - 1) + 1;
	if (size <= 0)
		str_size = 1;
	if (!(str = (char *)malloc(str_size * sizeof(char))))
		return (0);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	result = malloc_str(size, strs, sep);
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			result[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i != size - 1)
			result[k++] = sep[j++];
	}
	result[k] = '\0';
	return (result);
}
