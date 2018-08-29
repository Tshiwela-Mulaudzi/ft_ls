/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigR.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:20:21 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 12:07:36 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	bigR(t_dir *list, t_env *input)
{
	t_dir *tempo;

	tempo = list;
	while (tempo != NULL)
	{
		if (tempo ->is_dir == 1 && tempo -> dir[0] != '.')
			execute(tempo -> link, input);
		tempo = tempo ->next;
	}
}
