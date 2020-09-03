/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:35:34 by echin             #+#    #+#             */
/*   Updated: 2020/08/23 20:34:21 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_DICT_H
# define FT_PARSE_DICT_H

int		count_lines(char *file_path);
int		*count_lines_length(int fd, int n_lines);
t_cell	*parse_dict(int fd, int *lines_length, t_cell *list);
t_cell	*create_dict(char *file_path);

#endif
