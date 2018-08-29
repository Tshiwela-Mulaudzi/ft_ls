/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:52:35 by tmulaud           #+#    #+#             */
/*   Updated: 2018/08/28 14:39:14 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/dir.h>
#include <uuid/uuid.h>


typedef struct		s_dir
{
	char			*dir;
	char			*link;
	time_t			time;
	int				is_dir;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_env
{
	int				earl;
	int				ay;
	int				smallr;
	int				tee;
	int				bigr;
	char			*link;
	DIR				*dirp;
	struct dirent	*directory;
	struct stat		sb;
	t_dir			*list;
}					t_env;

void 		timer(struct stat fstat, t_dir *tempo);
char 		user(struct stat fstat);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char const *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
void		permissions(t_dir *temp, struct stat fstat);
void 		printL(t_dir *list);
void		reverse(t_dir **head_ref);
void		bigR(t_dir *list, t_env *input);
void 		smallR(t_dir **head_ref);
void        do_ls(t_env *input);
void        ft_ls(t_env *input);
int			main(int argc, char **argv);
int			get_arguments(t_env *input, char *argv);
int			compare1(t_dir directory1, t_dir directory2);
int			compare2(t_dir directory1, t_dir directory2);
void		sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done);
void 		delegate(t_dir *list, t_env *input, char *link);
void 		execute(char *dir, t_env *input);
int			ft_atoi(const char *str);
static char *getstr(char *ptr);
char		*ft_itoa(int n);
int			ft_isdigit(int c);
void		*ft_memalloc(size_t size);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_memset(void *b, int c, size_t len);

#endif
