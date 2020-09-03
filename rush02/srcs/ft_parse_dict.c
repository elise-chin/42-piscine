/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:34:46 by echin             #+#    #+#             */
/*   Updated: 2020/08/23 21:36:07 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		count_lines(char *dict_path)
{
	int		fd;
	char	buf;
	int		n_lines;

	n_lines = 0;
	if ((fd = safe_open(dict_path)))
	{
		while (read(fd, &buf, 1) > 0)
			if (buf == '\n')
				n_lines++;
	}
	safe_close(fd);
	return (n_lines);
}

int		*count_lines_length(int fd, int n_lines)
{
	char	buf;
	int		*lines_length;
	int		w;
	int		i;

	if (!(lines_length = (int *)malloc(n_lines * sizeof(int))))
	{
		message_error();
		return (0);
	}
	i = 0;
	while (i < n_lines)
		lines_length[i++] = 1;
	w = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			w++;
		else
			lines_length[w]++;
	}
	return (lines_length);
}

t_cell	*parse_dict(int fd, int *lines_length, t_cell *list)
{
	char	*buf;
	char	*k;
	char	*v;
	int		line;

	line = 0;
	buf = malloc((lines_length[0] + 1) * sizeof(char));
	while ((read(fd, buf, lines_length[line])) > 0)
	{
		k = (char *)malloc((lines_length[line] + 1) * sizeof(char));
		v = (char *)malloc((lines_length[line] + 1) * sizeof(char));
		if (!ft_is_empty_line(buf))
		{
			if (ft_split(buf, lines_length[line], k, v))
				list = add_at(list, k, v, line);
			else
				return (0);
		}
		else
			list = add_at(list, ft_strcpy(k, " "), ft_strcpy(v, " "), line);
		free(buf);
		buf = malloc((lines_length[++line] + 1) * sizeof(char));
	}
	free(buf);
	return (list);
}

t_cell	*create_dict(char *file_path)
{
	int		n_lines;
	int		*lines_length;
	t_cell	*list;
	int		fd;

	n_lines = count_lines(file_path);
	if ((fd = safe_open(file_path)))
		lines_length = count_lines_length(fd, n_lines);
	else
		return (0);
	safe_close(fd);
	list = empty_list();
	if ((fd = safe_open(file_path)))
		list = parse_dict(fd, lines_length, list);
	else
		return (0);
	safe_close(fd);
	free(lines_length);
	return (list);
}
