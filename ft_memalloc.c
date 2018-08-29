/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:33:23 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 11:16:11 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_memalloc(size_t size)
{
	void	*something;

	something = malloc(size);
	if (something == NULL)
	{
		return (NULL);
	}
	ft_memset(something, 0, size);
	return (something);
}
