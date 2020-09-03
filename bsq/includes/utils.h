/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:59:24 by abaudot           #+#    #+#             */
/*   Updated: 2020/08/27 10:34:54 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_min(int x, int y);
int		ft_max(int x, int y);
int		safe_open(char *path);
int		safe_close(int fd);
int		ft_atoi(char *str, int size);
int		*init_tab(int size);
int		duplicates(char a, char b, char c);
void	set_triplet(t_char_triplet *car, char *line, int size);
t_sqr	null_sqr(int size);
t_sqr	largest_sqr_return(t_sqr sqr, int fd);
#endif
