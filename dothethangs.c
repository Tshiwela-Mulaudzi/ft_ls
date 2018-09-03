/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dothethangs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:07:05 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/30 16:17:24 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	delegate(t_dir *list, t_env *input, char *link)
{
	t_dir *tempo;

	if (input->tee == 1)
		sort_list(&list, compare2, 0);
	if (input->smallar == 1)
		smallr(&list);
	if (input->bigar)
		ft_putstr(ft_strjoin(link, ":\n"));
	if (input->earl)
		printl(list);
	else
	{
		tempo = list;
		while (tempo != NULL)
		{
			ft_putstr(tempo->dir);
			tempo = tempo->next;
			if (tempo != NULL)
				write(1, "\n", 1);
		}
	}
	write(1, "\n", 1);
	if (input->bigar == 1)
		bigr(list, input);
}

void	execute(char *dir, t_env *input)
{
	t_dir *list;
	t_dir *tempo;

	list = NULL;
	if ((input->dirp = opendir(dir)) != NULL)
	{
		while ((input->directory = readdir(input->dirp)) != NULL)
		{
			if (input->directory->d_name[0] != '.' || input->ay == 1)
			{
				tempo = (t_dir *)malloc(sizeof(t_dir));
				tempo->dir = input->directory->d_name;
				tempo->link = ft_strjoin(ft_strjoin(dir, "/"),
						input->directory->d_name);
				lstat(tempo->link, &input->sb);
				tempo->time = input->sb.st_mtime;
				if (S_ISDIR(input->sb.st_mode) == 1)
					tempo->is_dir = 1;
				tempo->next = list;
				list = tempo;
			}
		}
		sort_list(&list, compare1, 0);
		delegate(list, input, dir);
	}
}
