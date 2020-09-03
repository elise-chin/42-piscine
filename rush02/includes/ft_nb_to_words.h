/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_to_words.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:50 by echin             #+#    #+#             */
/*   Updated: 2020/08/23 20:46:00 by wel-mahj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NB_TO_WORDS_H
# define FT_NB_TO_WORDS_H

void	units(char *nb, int len, int pos, t_cell *dict);
void	tens_power(char *nb, int len, int pos, t_cell *dict);
void	hundreds(char *nb, int len, int pos, t_cell *dict);
void	tens(char *nb, int len, int pos, t_cell *dict);
void	write_nb(char *nb, t_cell *dict);

#endif
