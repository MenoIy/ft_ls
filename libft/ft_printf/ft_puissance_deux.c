/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance_deux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 15:14:40 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 14:41:43 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_puissance_deux(int puissance)
{
	char	*res;
	char	*tmp;
	int		i;

	if (puissance == 0)
	{
		res = ft_strdup("1");
		return (res);
	}
	res = ft_strdup("2");
	i = puissance - 1;
	while (i > 0)
	{
		tmp = res;
		res = ft_addition_nb(res, res);
		free(tmp);
		i--;
	}
	return (res);
}
