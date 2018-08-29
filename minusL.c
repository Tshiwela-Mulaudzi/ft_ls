/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minusL.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:46:21 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 17:57:40 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void printL(t_dir *list)
{
	char	s;
	char 	*size;
	int 	length;
	int 	counter;
	struct 	stat fstat;
	t_dir	*tempo;

	tempo = list;
	while (tempo != NULL)
	{
		lstat(tempo -> link, &fstat);
		permissions(tempo, fstat);
		ft_putnbr(fstat.st_nlink);
		ft_putchar(' ');
		s = user(fstat);
		ft_putstr(&s);
		counter = 5;
		size = ft_itoa(fstat.st_size);
		length = ft_strlen(size);
		while (counter--)
			ft_putchar(' ');
		ft_putstr(ft_strjoin(size, "  "));
		timer(fstat, tempo);
		tempo = tempo -> next;
		(tempo != NULL) ? ft_putchar('\n'): 0;
	}
}
void permissions(t_dir *tempo, struct stat fstat)
{
	if (tempo -> is_dir)
		ft_putchar('d');
	else
		ft_putchar((S_ISLNK(fstat.st_mode)) ? 'l' : '-');
	ft_putchar((fstat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXOTH) ? 'x' : '-');
	write(1, " ", 1);
}
