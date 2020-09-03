/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 22:22:40 by echin             #+#    #+#             */
/*   Updated: 2020/08/27 11:46:48 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "utils.h"

int		read_line(int fd)
{
	char	buf;
	int		size;

	size = 0;
	while (read(fd, &buf, 1) > 0 && buf != '\n')
		size++;
	return (size);
}

int		board_height_car(char *file_path, t_int_tuple *bs, t_char_triplet *car)
{
	char	*line;
	int		fd;
	int		size;

	if ((fd = safe_open(file_path)))
	{
		if ((size = read_line(fd)) < 4)
			return (0);
		safe_close(fd);
	}
	if ((fd = safe_open(file_path)))
	{
		if ((line = malloc(size * sizeof(char))))
		{
			read(fd, line, size);
			if (duplicates(line[size - 1], line[size - 2], line[size - 3]))
				return (0);
			set_triplet(car, line, size);
			bs->i = ft_atoi(line, size - 3);
			free(line);
			return (fd);
		}
	}
	return (0);
}

int		board_width(int fd, t_int_tuple *bs)
{
	int	width;

	if ((width = read_line(fd)) > 0)
	{
		bs->j = width;
		safe_close(fd);
		return (1);
	}
	safe_close(fd);
	return (0);
}

int		board_info(char *file_path, t_int_tuple *bs, t_char_triplet *car)
{
	int		fd;
	char	buf;

	if ((fd = board_height_car(file_path, bs, car)) != 0)
	{
		read(fd, &buf, 1);
		if (board_width(fd, bs))
			return (fd);
	}
	return (-1);
}

char	*stdin_to_file(void)
{
	int		fd;
	char	buf;
	char	*filename;

	filename = "./srcs/stdin_board.txt";
	if ((fd = open(filename, O_WRONLY | O_TRUNC)) != -1)
	{
		while (read(STDIN_FILENO, &buf, 1) > 0)
			write(fd, &buf, 1);
		safe_close(fd);
		return (filename);
	}
	return (0);
}
