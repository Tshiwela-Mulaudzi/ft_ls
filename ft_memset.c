/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:32:11 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 11:54:55 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			counter;
	unsigned char	*pointer;

	counter = 0;
	pointer = (unsigned char*)b;
	while (counter < len)
	{
		pointer[counter] = c;
		counter++;
	}
	return (b);
}
