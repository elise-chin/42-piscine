/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 14:30:32 by echin             #+#    #+#             */
/*   Updated: 2020/08/17 17:36:03 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

int		count_words(char *str, char *charset)
{
	int n_words;
	int i;

	n_words = 0;
	i = 0;
	while (is_sep(str[i], charset))
		i++;
	while (str[i])
	{
		if (is_sep(str[i], charset))
		{
			n_words++;
			while (is_sep(str[i], charset))
				i++;
		}
		else
			i++;
	}
	if (!is_sep(str[i - 1], charset))
		n_words++;
	return (n_words);
}

int		*get_words_size(char *str, char *charset)
{
	int	w;
	int	i;
	int	words_count;
	int	*words_size;

	words_count = count_words(str, charset);
	if (!(words_size = (int *)malloc((words_count + 1) * sizeof(int))))
		return (0);
	i = -1;
	while (++i <= words_count)
		words_size[i] = 0;
	i = 0;
	w = 0;
	while (is_sep(str[i], charset))
		i++;
	while (str[i])
	{
		if (!is_sep(str[i], charset))
			words_size[w]++;
		else if (i > 0 && !is_sep(str[i - 1], charset)
				&& is_sep(str[i], charset))
			w++;
		i++;
	}
	return (words_size);
}

int		create_splits(char **splits, char *str, char *charset)
{
	int i;
	int w;
	int j;
	int *sizes;

	i = -1;
	w = -1;
	sizes = get_words_size(str, charset);
	while (str[++i])
	{
		if (!is_sep(str[i], charset))
		{
			if (i == 0 || (i > 0 && is_sep(str[i - 1], charset)))
			{
				j = 0;
				w++;
				splits[w] = (char *)malloc((sizes[w] + 1) * sizeof(char));
				if (!splits[w])
					return (0);
			}
			splits[w][j] = str[i];
			splits[w][++j] = '\0';
		}
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	int		words_count;
	char	**splits;

	words_count = count_words(str, charset);
	if (!(splits = (char **)malloc((words_count + 1) * sizeof(char *))))
		return (0);
	if (!create_splits(splits, str, charset))
		return (0);
	splits[words_count] = 0;
	return (splits);
}
