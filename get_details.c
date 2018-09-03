/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_details.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 07:45:43 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/30 12:52:41 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	timer(struct stat fstat, t_dir *tempo)
{
	char	time_format[13];
	char	*begin;
	char	buffer[64];
	size_t	length;

	(void)fstat;
	begin = ctime(&tempo->time);
	ft_memcpy(time_format, &begin[4], 12);
	time_format[12] = '\0';
	ft_putstr(time_format);
	ft_putstr("   ");
	ft_putstr(tempo->dir);
	if (S_ISLNK(fstat.st_mode))
	{
		ft_putstr(" -> ");
		length = readlink(tempo->link, buffer, 64);
		buffer[length] = '\0';
		ft_putstr(buffer);
	}
}

char	*user(struct stat fstat)
{
	char			*joined;
	struct passwd	*password;
	struct group	*grp;

	password = getpwuid(fstat.st_uid);
	grp = getgrgid(fstat.st_gid);
	joined = ft_strjoin(ft_strjoin(password->pw_name, "  "), grp->gr_name);
	return (ft_strjoin(joined, " "));
}

int		get_arguments(t_env *input, char *argv)
{
	int checker;

	checker = 1;
	while (argv[checker] != '\0')
	{
		if (argv[checker] == 'l')
			input->earl = 1;
		else if (argv[checker] == 'a')
			input->ay = 1;
		else if (argv[checker] == 'r')
			input->smallar = 1;
		else if (argv[checker] == 't')
			input->tee = 1;
		else if (argv[checker] == 'R')
			input->bigar = 1;
		else
		{
			ft_putstr(argv);
			write(1, ": Invalid argument\n", 19);
			return (0);
		}
		checker = checker + 1;
	}
	return (1);
}
