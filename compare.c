/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:45:43 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 11:17:17 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		compare1(t_dir directory1, t_dir directory2)
{
	return (ft_strcmp(directory1.dir, directory2.dir));
}

int		compare2(t_dir directory1, t_dir directory2)
{
	if (directory1.time < directory2.time)
		return (1);
	else
		return (0);
}

void	sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done)
{
	t_dir	**source;
	t_dir	*tempo;
	t_dir	*next;

	while (!done && *head != NULL && (*head)->next != NULL)
	{
		source = head;
		tempo = *head;
		next = (*head)->next;
		done = 1;
		while (next)
		{
			if (cmp(*tempo, *next) > 0)
			{
				tempo ->next = next->next;
				next->next = tempo;
				*source = next;
				done = 0;
			}
			source = &tempo ->next;
			tempo = next;
			next = next->next;
		}
	}
}
