/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 12:16:36 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/29 16:58:13 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*destblock;
	char	*srcblock;

	destblock = (char*)dst;
	srcblock = (char*)src;
	while (n--)
	{
		*destblock++ = *srcblock++;
	}
	return (dst);
}
