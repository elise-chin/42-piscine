/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mahj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 11:50:19 by wel-mahj          #+#    #+#             */
/*   Updated: 2020/08/23 20:26:02 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef	struct		s_cell
{
	char			*key;
	char			*value;
	struct s_cell	*next;
}					t_cell;

t_cell				*create_cell(char *key, char *value);
t_cell				*empty_list(void);
int					is_empty_list(t_cell *l);
t_cell				*add_at(t_cell *l, char *key, char *value, int pos);
char				*get_value(t_cell *l, char *key);

#endif
