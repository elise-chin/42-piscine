/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 10:27:42 by echin             #+#    #+#             */
/*   Updated: 2020/08/07 10:28:24 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int begin_word;

	i = 0;
	begin_word = 1;
	while (str[i])
	{
		if (is_alphanumeric(str[i]))
		{
			if (begin_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (!begin_word && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			begin_word = 0;
		}
		else
			begin_word = 1;
		i++;
	}
	return (str);
}
