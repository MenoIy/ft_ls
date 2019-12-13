/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:06:28 by kdaou             #+#    #+#             */
/*   Updated: 2019/03/12 17:52:57 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_get_acl(char *str, char *path)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t		xattr;

	acl = NULL;
	xattr = 0;
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		str[10] = '@';
	else if (acl != NULL)
		str[10] = '+';
	else
		str[10] = ' ';
	acl_free(acl);
}

static char	ft_get_type(mode_t n)
{
	if (n == S_IFDIR)
		return ('d');
	else if (n == S_IFLNK)
		return ('l');
	else if (n == S_IFBLK)
		return ('b');
	else if (n == S_IFSOCK)
		return ('s');
	else if (n == S_IFREG)
		return ('-');
	else if (n == S_IFIFO)
		return ('p');
	else if (n == S_IFCHR)
		return ('c');
	return ('?');
}

static void	ft_get_right(mode_t stat, char *path, char *str)
{
	str[0] = ft_get_type(stat & S_IFMT);
	str[1] = (stat & S_IRUSR) ? 'r' : '-';
	str[2] = (stat & S_IWUSR) ? 'w' : '-';
	str[3] = (stat & S_IXUSR) ? 'x' : '-';
	if (stat & S_ISUID)
		str[3] = (stat & S_IXUSR) ? 's' : 'S';
	str[4] = (stat & S_IRGRP) ? 'r' : '-';
	str[5] = (stat & S_IWGRP) ? 'w' : '-';
	str[6] = (stat & S_IXGRP) ? 'x' : '-';
	if (stat & S_ISUID)
		str[6] = (stat & S_IXGRP) ? 's' : 'S';
	str[7] = (stat & S_IROTH) ? 'r' : '-';
	str[8] = (stat & S_IWOTH) ? 'w' : '-';
	str[9] = (stat & S_IXOTH) ? 'x' : '-';
	if (stat & S_ISVTX)
		str[9] = (stat & S_IXOTH) ? 't' : 'T';
	str[10] = ' ';
	ft_get_acl(str, path);
}

void		ft_read_biggest_field(t_ls *ls, t_file *file)
{
	int n;

	n = 0;
	file->time = ft_get_str_part(file->mtime, ls->option);
	if (((n = ft_strlen(file->name))) > ls->bigname)
		ls->bigname = n;
	if (((n = ft_digitlen(file->size, 10))) > ls->bigsize)
		ls->bigsize = n;
	if (((n = ft_digitlen(file->link, 10))) > ls->biglink)
		ls->biglink = n;
	if (*file->right == 'c' || *file->right == 'b')
		ls->bigsize = 9;
	if (file->uid && file->grp)
	{
		if (((n = ft_strlen(file->uid))) > ls->uid)
			ls->uid = n;
		if (((n = ft_strlen(file->grp))) > ls->grp)
			ls->grp = n;
	}
}

void		ft_get_info(t_ls *ls, char *path, char *file, t_file *info)
{
	struct stat		filestat;
	struct group	*g;
	struct passwd	*uid;

	if (lstat(path, &filestat))
	{
		ft_printf("./ft_ls: %s: %s\n", path, strerror(errno));
		info->error = 1;
		return ;
	}
	g = getgrgid(filestat.st_gid);
	uid = getpwuid(filestat.st_uid);
	info->name = ft_strdup(file);
	info->path = ft_strdup(path);
	info->rdev = filestat.st_rdev;
	ft_get_right(filestat.st_mode, path, info->right);
	info->full_link = ft_read_link(path);
	info->uid = ft_strdup(uid->pw_name);
	info->grp = ft_strdup(g->gr_name);
	info->size = filestat.st_size;
	info->mtime = (ls->option & SU) ? filestat.st_atime : filestat.st_mtime;
	info->mtime = (ls->option & SC) ? filestat.st_ctime : info->mtime;
	info->link = filestat.st_nlink;
	info->bloks = filestat.st_blocks;
	ft_read_biggest_field(ls, info);
}
