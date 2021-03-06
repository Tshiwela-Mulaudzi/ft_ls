/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:20:00 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 11:17:31 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_atoi(const char *str)
{
	int			counter;
	long int	n;

	counter = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == 32)
		str++;
	if (*str == '-')
		n = -1;
	else
		n = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		counter = (counter * 10) + (*str++ - '0');
	return (counter * n);
}
