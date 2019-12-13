/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_ls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:59:46 by kdaou             #+#    #+#             */
/*   Updated: 2019/03/16 14:53:12 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_del_file(t_file **file)
{
	free((*file)->name);
	free((*file)->path);
	free((*file)->uid);
	free((*file)->grp);
	free((*file)->right);
	free((*file)->full_link);
	free((*file)->time);
	(*file)->size = 0;
	(*file)->mtime = 0;
	(*file)->link = 0;
	(*file)->bloks = 0;
	(*file)->error = 0;
	ft_memdel((void **)file);
}

void		ft_traitement_ls(char *path, t_ls **ls, char *file)
{
	t_file	*info_file;

	info_file = ft_new_struct_file();
	if (!(*ls)->first && (*ls)->option & BA && (ft_strequ(file, ".")
				|| ft_strequ(file, "..")))
		return ;
	if ((*ls)->option & FL || (*ls)->first)
	{
		ft_get_info(*ls, path, file, info_file);
		(*ls)->arg_nb++;
	}
	else
	{
		info_file->name = ft_strdup(file);
		info_file->path = ft_strdup(path);
		ft_read_biggest_field(*ls, info_file);
	}
	if (!info_file->error)
	{
		ft_lstadd_end(&(*ls)->list,
				ft_lstnew((t_file *)info_file, sizeof(t_file *)));
		(*ls)->total += info_file->bloks + 0 * (*ls)->file_nb++;
	}
	if (info_file->error)
		ft_del_file(&info_file);
}
