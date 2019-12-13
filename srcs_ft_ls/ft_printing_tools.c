/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 08:06:17 by kdaou             #+#    #+#             */
/*   Updated: 2019/03/12 14:51:17 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_get_row_nb(t_ls *ls)
{
	struct winsize	win_size;
	int				col_nb;
	int				big;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &win_size);
	big = ls->bigname + (ls->bigname % 8 == 0);
	ls->bigname = 8 * (big / 8 + (big % 8 != 0));
	col_nb = win_size.ws_col / ls->bigname;
	if (col_nb == 0)
	{
		col_nb = 1;
		ls->bigname = 0;
	}
	return (ls->file_nb / col_nb + (ls->file_nb % col_nb != 0));
}

static int	ft_print_file_listed(t_list *list, t_ls *ls, int is_dir)
{
	t_file	*file;
	int		ret;

	ret = 0;
	while (list)
	{
		file = (t_file *)list->content;
		if ((*file->right != 'd' && is_dir) || !is_dir)
		{
			ret = ft_printf("%s%*ld", file->right, ls->biglink + 1, file->link);
			ft_printf(" %*s  %*s  ", -ls->uid, file->uid, -ls->grp, file->grp);
			if (*file->right == 'c' || *file->right == 'b')
				ft_printf("%4d,%4d", major(file->rdev), minor(file->rdev));
			else
				ft_printf("%*ld", ls->bigsize, file->size);
			ft_printf(" %s %s", file->time, file->name);
			if (*file->right == 'l')
				ft_printf(" -> %s\n", file->full_link);
			else
				ft_printf("\n");
		}
		list = list->next;
	}
	return (ret);
}

static int	ft_print_file_multi_colonne(t_list *list, int is_dir, int n, int f)
{
	t_file	*file;
	t_list	*cur;
	int		j;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (list && i < n)
	{
		j = 0;
		while ((cur = ft_lst_at(list, j * n)))
		{
			file = (t_file *)cur->content;
			if ((!ft_is_dir(&file->path, 0) && is_dir) || !is_dir)
				ret = ft_printf("%*s", ft_lst_at(cur, n) ? -f : 0, file->name);
			j += 1;
		}
		ft_putstr(ret != 0 ? "\n" : "");
		list = list->next;
		i++;
	}
	return (ret);
}

static int	ft_print_file_one_colonne(t_list *list, int is_dir)
{
	t_file	*file;
	int		ret;

	ret = 0;
	while (list)
	{
		file = (t_file *)list->content;
		if ((!ft_is_dir(&file->path, 0) && is_dir) || !is_dir)
			ret = ft_printf("%s\n", file->name);
		list = list->next;
	}
	return (ret);
}

int			ft_print_file(t_ls *ls, int is_dir)
{
	t_list	*list;
	int		n;

	list = ls->list;
	n = 0;
	if (ls->option & SL)
	{
		if ((ls->option & BR && !ls->first) || (!is_dir && ls->file_nb))
			ft_printf("total %d\n", ls->total);
		return (ft_print_file_listed(list, ls, is_dir));
	}
	else if (ls->option & ONE)
		return (ft_print_file_one_colonne(list, is_dir));
	else
	{
		n = ft_get_row_nb(ls);
		return (ft_print_file_multi_colonne(list, is_dir, n, ls->bigname));
	}
	return (0);
}
