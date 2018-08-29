/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallR.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:45:10 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 15:20:08 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void smallR(t_dir **head_ref)
{
	t_dir *prev;
	t_dir *current;
	t_dir *next;

	current = *head_ref;
	prev = NULL;
	while (current != NULL)
	{
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}
