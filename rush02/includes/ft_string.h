/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mahj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 11:29:24 by wel-mahj          #+#    #+#             */
/*   Updated: 2020/08/23 17:55:10 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_split(char *str, int size, char *key, char *value);
int		ft_is_empty_line(char *str);
#endif
