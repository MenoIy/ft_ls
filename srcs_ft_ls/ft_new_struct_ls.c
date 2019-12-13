/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_struct_ls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:44:42 by kdaou             #+#    #+#             */
/*   Updated: 2019/03/16 14:46:29 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_del(void *content, size_t size)
{
	(void)size;
	free(content);
}

t_ls		*ft_new_struct_ls(void)
{
	t_ls	*ls;

	if (!(ls = (t_ls *)malloc(sizeof(t_ls))))
		return (NULL);
	ls->list = NULL;
	ls->bigname = 0;
	ls->bigsize = 0;
	ls->uid = 0;
	ls->grp = 0;
	ls->biglink = 0;
	ls->option = 0;
	ls->file_nb = 0;
	ls->total = 0;
	ls->first = 0;
	ls->arg_nb = 0;
	return (ls);
}

t_file		*ft_new_struct_file(void)
{
	t_file *file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	file->name = NULL;
	file->path = NULL;
	file->uid = NULL;
	file->grp = NULL;
	file->time = NULL;
	file->right = ft_strnew(12);
	file->full_link = NULL;
	file->size = 0;
	file->mtime = 0;
	file->link = 0;
	file->bloks = 0;
	file->error = 0;
	file->rdev = 0;
	return (file);
}

static void	ft_del_struct_file(t_file **file)
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
}

void		ft_del_struct_ls(t_ls **ls)
{
	t_list	*tmp;
	t_file	*file;

	tmp = (*ls)->list;
	while ((*ls)->list)
	{
		file = (t_file *)(*ls)->list->content;
		ft_del_struct_file(&file);
		(*ls)->list = (*ls)->list->next;
	}
	(*ls)->list = tmp;
	ft_lstdel(&(*ls)->list, &ft_del);
	ft_memdel((void **)ls);
}
