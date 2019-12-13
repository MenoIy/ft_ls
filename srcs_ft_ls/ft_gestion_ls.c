/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:18:40 by kdaou             #+#    #+#             */
/*   Updated: 2019/03/16 14:51:18 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls	*ft_open_print_dir(t_file *file, unsigned long option)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	t_ls			*ls;
	char			*str;

	if ((pdir = opendir(file->path)) == NULL)
	{
		ft_printf("./ft_ls: %s: %s\n", file->name, strerror(errno));
		return (NULL);
	}
	ls = ft_new_struct_ls();
	ls->option = option;
	while ((pdirent = readdir(pdir)) != NULL)
	{
		str = ft_get_path(file->path, pdirent->d_name);
		if (option & SA || option & BA || *pdirent->d_name != '.')
			ft_traitement_ls(str, &ls, pdirent->d_name);
		free(str);
	}
	closedir(pdir);
	ft_sorting_ls(&ls);
	return (ls);
}

static void	ft_gestion_recursive_ls(t_ls *ls)
{
	t_file	*file;
	t_list	*list;
	t_ls	*lsr;
	int		ret;

	ret = ft_print_file(ls, ls->first);
	list = ls->list;
	while (list)
	{
		file = (t_file *)list->content;
		if ((ft_is_dir(&file->path, 1) && ls->first &&
					!(ls->option & SL)) || *file->right == 'd')
			if ((!ft_strequ(file->name, ".") && !ft_strequ(file->name, ".."))
					|| ls->first)
			{
				ft_putstr(ret ? "\n" : "");
				if (ls->arg_nb > 1 || (ls->file_nb && ret))
					ret = ft_printf("%s:\n", file->path);
				if ((file->right[3] == 'x' || file->right[3] == 's') &&
						(lsr = ft_open_print_dir(file, ls->option)))
					ft_gestion_recursive_ls(lsr);
			}
		list = list->next;
	}
	ft_del_struct_ls(&ls);
}

static int	ft_open_read_dir(t_file *file, unsigned long option)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	t_ls			*ls;
	char			*str;

	if ((pdir = opendir(file->path)) == NULL)
		return (ft_printf("./ft_ls: %s: %s\n", file->name, strerror(errno)));
	ls = ft_new_struct_ls();
	ls->option = option;
	while ((pdirent = readdir(pdir)) != NULL)
	{
		str = ft_get_path(file->path, pdirent->d_name);
		if (option & SA || option & BA || *pdirent->d_name != '.')
			ft_traitement_ls(str, &ls, pdirent->d_name);
		free(str);
	}
	closedir(pdir);
	ft_sorting_ls(&ls);
	ft_print_file(ls, 0);
	ft_del_struct_ls(&ls);
	return (1);
}

static void	ft_gestion_normal_ls(t_ls *ls)
{
	t_file	*file;
	t_list	*list;
	int		ret;

	ret = ft_print_file(ls, 1);
	list = ls->list;
	while (list)
	{
		file = (t_file *)list->content;
		if (ft_is_dir(&file->path, 1) &&
				!(*file->right == 'l' && ls->option & SL))
		{
			if (ret)
				ft_putchar('\n');
			if (ls->arg_nb > 1)
				ret = ft_printf("%s:\n", file->name);
			if (file->right[3] == 'x' || file->right[3] == 's'
					|| !(ls->option & SL))
				ft_open_read_dir(file, ls->option);
		}
		list = list->next;
	}
}

void		ft_gestion_ls(t_ls *ls)
{
	if (ls->option & BR)
		ft_gestion_recursive_ls(ls);
	else
		ft_gestion_normal_ls(ls);
}
