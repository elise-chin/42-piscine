/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:52:12 by echin             #+#    #+#             */
/*   Updated: 2020/08/23 16:53:08 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	safe_open(char *path)
{
	int fd;

	fd = 0;
	if ((fd = open(path, O_RDONLY)) >= 0)
		return (fd);
	else
		return (0);
}

int	safe_close(int fd)
{
	if (!close(fd))
		return (1);
	else
		return (0);
}
