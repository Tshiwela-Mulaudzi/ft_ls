/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:50:38 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 14:20:16 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		i;
	t_env	input;
	t_dir	*tempo;

	i = 1;
	input.list = NULL;
	while (i < argc)
	{
		if (argv[i][0] != '-' && (tempo = (t_dir *)malloc(sizeof(t_dir))))
		{
			tempo ->dir = argv[i];
			tempo ->next = input.list;
			input.list = tempo;
			ft_putstr("ft_ls: ");
			ft_putstr(argv[i]);
			write(1, ": No such file or directory\n", 28);
		}
		else if (get_arguments(&input, argv[i]) == 0)
			return (0);
		i = i + 1;
	}
	if (input.list == NULL)
		do_ls(&input);
	ft_ls(&input);
}
