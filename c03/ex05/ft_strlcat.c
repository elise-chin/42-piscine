/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:21:24 by echin             #+#    #+#             */
/*   Updated: 2020/08/21 10:43:30 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	int				limit;
	unsigned int	dest_size;
	unsigned int	src_size;

	if (dest && src)
	{
		src_size = ft_strlen(src);
		dest_size = ft_strlen(dest);
		if (dest_size >= size || !size)
			return (size + src_size);
		i = 0;
		limit = size - dest_size - 1;
		while (src[i] && i < limit)
		{
			dest[dest_size + i] = src[i];
			i++;
		}
		dest[dest_size + i] = '\0';
		return (dest_size + src_size);
	}
	else
		return (0);
}
