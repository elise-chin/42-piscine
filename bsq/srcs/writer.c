/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:15:49 by abaudot           #+#    #+#             */
/*   Updated: 2020/08/27 00:52:36 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static void	fill_sqr(char *sqr_buf, char sqr_char, int sqr_size)
{
	while (sqr_size--)
		*sqr_buf++ = sqr_char;
}

static void	display_sqrt(int fd, int sqr_size, char *sqr_buf, char sqr_char)
{
	read(fd, sqr_buf, sqr_size);
	fill_sqr(sqr_buf, sqr_char, sqr_size);
	write(1, sqr_buf, sqr_size);
}

static void	display_headline(int fd, int n, t_sqr sqr)
{
	const int	buf_size = (sqr.coord.i - sqr.size) * (n + 1);
	char		*buf;

	if (!(buf = (char *)malloc(sizeof(char) * buf_size)))
		return ;
	if (read(fd, buf, buf_size) == -1)
		return ;
	write(1, buf, buf_size);
	free(buf);
}

static void	display_last_lines(int fd, t_int_tuple board_size, t_sqr sqr)
{
	const int	buf_size = (board_size.i - sqr.coord.i) * (board_size.j + 1);
	char		*buf;

	if (!(buf = (char *)malloc(sizeof(char) * buf_size)))
		return ;
	if (read(fd, buf, buf_size) == -1)
		return ;
	write(1, buf, buf_size);
	free(buf);
}

void		show_answer(int fd, t_sqr s, t_int_tuple b_s, char sqr_char)
{
	const t_int_tuple	t_d = {s.coord.j - s.size, b_s.j - s.coord.j + 1};
	const int			save = s.size;
	char				*sqr_buf;
	char				*tail_buf;
	char				*head_buf;

	if (!(tail_buf = (char *)malloc(sizeof(char) * t_d.i)))
		return ;
	if (!(head_buf = (char *)malloc(sizeof(char) * t_d.j)))
		return ;
	if (!(sqr_buf = (char *)malloc(sizeof(char) * s.size)))
		return ;
	display_headline(fd, b_s.j, s);
	while (s.size--)
	{
		read(fd, tail_buf, t_d.i);
		write(1, tail_buf, t_d.i);
		display_sqrt(fd, save, sqr_buf, sqr_char);
		read(fd, head_buf, t_d.j);
		write(1, head_buf, t_d.j);
	}
	display_last_lines(fd, b_s, s);
	free(tail_buf);
	free(head_buf);
	free(sqr_buf);
}
