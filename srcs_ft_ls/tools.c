/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:57:40 by kdaou             #+#    #+#             */
/*   Updated: 2019/03/12 17:52:07 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_str_part(time_t mtime, unsigned long option)
{
	char	*ptr;
	char	*str;
	char	*tmp;
	char	*to_free;
	time_t	act;

	act = time(NULL);
	str = ctime(&mtime);
	if (option & 4096)
		ptr = ft_strsub(str, 4, 20);
	else if (mtime > act || act - mtime >= SEMI_YEAR)
	{
		to_free = ft_strsub(str, 4, 6);
		tmp = ft_strjoin(to_free, "  ");
		free(to_free);
		to_free = ft_strsub(str, 20, 4);
		ptr = ft_strjoin(tmp, to_free);
		free(to_free);
		free(tmp);
	}
	else
		ptr = ft_strsub(str, 4, 12);
	return (ptr);
}

char	*ft_get_path(char *str, char *file)
{
	char	*path;
	char	*out;
	int		len;

	len = ft_strlen(str) - 1;
	if (ft_strequ(str, "/") || str[len] == '/')
		path = ft_strdup(str);
	else
		path = ft_strjoin(str, "/");
	out = path;
	path = ft_strjoin(path, file);
	free(out);
	return (path);
}

int		ft_is_dir(char **path, int condition)
{
	struct stat	buff;
	char		*tmp;

	if (stat(*path, &buff))
		return (0);
	if (!S_ISDIR(buff.st_mode))
		return (0);
	if (condition && **path != '/')
	{
		tmp = ft_strjoin(*path, "/");
		free(*path);
		*path = tmp;
	}
	return (1);
}

char	*ft_read_link(char *path)
{
	char	buf[4096];
	size_t	size;

	size = readlink(path, buf, 4096);
	buf[size] = '\0';
	return (ft_strdup(buf));
}
