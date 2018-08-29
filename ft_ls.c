/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:25:24 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 15:46:20 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	do_ls(t_env *input)
{
	input->list = (t_dir *)malloc(sizeof(t_dir));
	input->list->dir = ".";
	input->list->next = NULL;
}

void	ft_ls(t_env *input)
{
	t_dir	*tempo;

	tempo = input->list;
	while (tempo != NULL)
	{
		execute(tempo->dir, input);
		tempo = tempo ->next;
	}
}

