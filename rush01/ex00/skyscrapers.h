/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:40:47 by echin             #+#    #+#             */
/*   Updated: 2020/08/16 16:12:39 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPERS_H
# define SKYSCRAPERS_H
# include <stdlib.h>
# include <unistd.h>
# define N 4

int		ft_strlen(char *str);
int		check_string(char *str);

int		*create_tab_arg(char *str);
int		**create_tab_res(void);

void	fill_first_numbers(int *tab, int **res);
void	fill_first_nb_one(int **res, int index_tab);
void	fill_first_nb_four(int **res, int index_tab);

void	ft_putchar(char c);
void	print_double_tab(int **tab);
void	print_tab_int(int *tab, int size);
void	print_error(void);

int		is_unique(int **res, int row, int col, int choice);
int		count_view_forward(int *row);
int		count_view_backward(int *row);
int		check_row(int *row, int left, int right);
int		count_values_in_row(int *row, int value);
int		satisfy_view(int **res, int *args, int row, int col);
int		is_possible_to_place(int **res, int *args, int *position, int choice);
int		*get_empty_cell(int **res);
int		backtrack(int **res, int *args);

#endif
