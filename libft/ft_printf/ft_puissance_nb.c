/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:32:12 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 14:43:17 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_puissance_nb(char *nb, int puissance)
{
	char	*res;
	char	*tmp;
	int		i;

	i = puissance;
	res = ft_strdup(nb);
	while (i > 1)
	{
		tmp = res;
		res = ft_multiple_nb(res, nb);
		free(tmp);
		i--;
	}
	return (res);
}
