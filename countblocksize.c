/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countblocksize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:18:24 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/03 14:26:37 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <string.h>

int getblocksize(char* directory)
{
	int size = 0;
	DIR *d;
	struct dirent *dir;
	struct stat fileStat;
   d = opendir(directory);
   if (d)
   {
	   while ((dir = readdir(d)) != NULL)
	   {
		   if (dir->d_name[0] != '.') 
		   { // Ignore hidden files
			// Create the path to stat
			char info_path[PATH_MAX + 1];
			strcpy(info_path, directory);
			if (directory[strlen(directory) - 1] != '/')
				strcat(info_path, "/");
			strcat(info_path, dir->d_name);
			stat(info_path, &fileStat);
			size += fileStat.st_blocks;
		   }
	   }
   }
   return size;
}
