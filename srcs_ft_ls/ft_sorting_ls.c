/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:25:36 by kdaou             #+#    #+#             */
/*   Updated: 2019/03/11 19:58:20 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_cmp_path(void *content1, void *content2)
{
	char	*str1;
	t_file	*file1;
	t_file	*file2;
	char	*str2;

	file1 = (t_file *)content1;
	file2 = (t_file *)content2;
	str1 = file1->name;
	str2 = file2->name;
	return (ft_strcmp(str1, str2));
}

static int	ft_cmp_size(void *content1, void *content2)
{
	t_file	*file1;
	t_file	*file2;

	file1 = (t_file *)content1;
	file2 = (t_file *)content2;
	if (file1->size - file2->size == 0)
		return (ft_strcmp(file1->name, file2->name));
	else
		return (file2->size - file1->size);
}

static	int	ft_cmp_time(void *content1, void *content2)
{
	t_file	*file1;
	t_file	*file2;

	file1 = (t_file *)content1;
	file2 = (t_file *)content2;
	if (file1->mtime - file2->mtime == 0)
		return (ft_strcmp(file1->name, file2->name));
	else
		return (file2->mtime - file1->mtime);
}

static void	ft_reverse_ls(t_list **list)
{
	t_list	*tmp;
	t_list	*cur;

	cur = NULL;
	while (*list)
	{
		tmp = (*list)->next;
		(*list)->next = cur;
		cur = (*list);
		(*list) = tmp;
	}
	*list = cur;
}

void		ft_sorting_ls(t_ls **ls)
{
	if ((*ls)->option & SF)
		(*ls)->option = (*ls)->option | SA;
	else if ((*ls)->option & BS)
		ft_list_sort((*ls)->list, (ft_cmp_size));
	else if ((*ls)->option & ST)
		ft_list_sort((*ls)->list, (ft_cmp_time));
	else
		ft_list_sort((*ls)->list, (ft_cmp_path));
	if ((*ls)->option & SR && !((*ls)->option & SF))
		ft_reverse_ls(&(*ls)->list);
}
