/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:03:19 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 11:02:12 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
