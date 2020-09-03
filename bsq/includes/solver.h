/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 20:29:57 by echin             #+#    #+#             */
/*   Updated: 2020/08/27 00:46:42 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "struct.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_min(int x, int y);
int		ft_max(int x, int y);
int		*init_tab(int size);
char	*stdin_to_file(void);
int		read_line(int fd);
int		board_info(char *file_p, t_int_tuple *board_size, t_char_triplet *car);
t_sqr	large_sqr(int fd, t_int_tuple board_size, t_char_triplet car, int *dp);
t_sqr	pre_solver(char *file_path, t_int_tuple board_size, t_char_triplet car);
int		solver(char *file_path);
void	show_answer(int fd, t_sqr sqr, t_int_tuple board_size, char sqr_char);
#endif
