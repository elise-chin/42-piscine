/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mahj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 19:07:38 by wel-mahj          #+#    #+#             */
/*   Updated: 2020/08/23 22:17:31 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		main(int argc, char **argv)
{
	t_cell	*dict;
	char	*nb;
	char	*nom_dico;

	if (argc == 2 || argc == 3)
	{
		nom_dico = (argc == 2) ? "dicts/numbers.dict" : argv[1];
		nb = argv[argc - 1];
		if (!is_positive_int(nb))
			return (message_error());
		else
		{
			if (!safe_open(nom_dico))
				return (message_dict_error());
			dict = create_dict(nom_dico);
			if (!valid_length(nb, dict))
				return (0);
			write_nb(nb, dict);
			free_list(dict);
		}
	}
	else
		return (message_error());
}
