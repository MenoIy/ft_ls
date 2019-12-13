/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:41:12 by kdaou             #+#    #+#             */
/*   Updated: 2019/03/16 14:43:51 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>
# include <errno.h>
# include <stdio.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# define SEMI_YEAR 15768000
# define SL 2
# define SA 4
# define BR 8
# define SR 16
# define ST 32
# define ONE 64
# define BS 128
# define SF 256
# define SU 512
# define SC 1024
# define BA 2048
# define BT 4096
# define FL	1706

typedef struct		s_file
{
	char			*name;
	char			*path;
	char			*uid;
	char			*grp;
	char			*right;
	char			*full_link;
	char			*time;
	long			size;
	time_t			mtime;
	long			link;
	long			bloks;
	int				error;
	dev_t			rdev;
}					t_file;

typedef struct		s_ls
{
	int				bigname;
	int				bigsize;
	int				uid;
	int				grp;
	int				biglink;
	t_list			*list;
	unsigned long	option;
	int				file_nb;
	long			total;
	int				first;
	int				arg_nb;
}					t_ls;

t_ls				*ft_new_struct_ls(void);
void				ft_del_struct_ls(t_ls **ls);
t_file				*ft_new_struct_file(void);
void				ft_traitement_ls(char *path, t_ls **ls, char *file);
void				ft_get_info(t_ls *ls, char *path, char *file, t_file *info);
void				ft_sorting_ls(t_ls **ls);
char				*ft_get_str_part(long mtime, unsigned long option);
char				*ft_get_path(char *str, char *file);
void				ft_read_biggest_field(t_ls *ls, t_file *file);
int					ft_is_dir(char **path, int condition);
char				*ft_read_link(char *path);
int					ft_print_file(t_ls *ls, int to_do);
void				ft_gestion_ls(t_ls *ls);

#endif
