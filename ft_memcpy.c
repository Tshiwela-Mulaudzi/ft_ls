/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 12:16:36 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 11:14:50 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
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
