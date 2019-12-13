/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:34:13 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/24 19:08:31 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*maillon;

	if (!(maillon = (t_list*)malloc(sizeof(size_t) * content_size)))
		return (NULL);
	maillon->content_size = content_size;
	if (!content)
		maillon->content_size = 0;
	maillon->content = (void *)content;
	maillon->next = NULL;
	return (maillon);
}
