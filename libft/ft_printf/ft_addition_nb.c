/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addition_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 13:19:04 by kdaou             #+#    #+#             */
/*   Updated: 2019/03/11 19:22:47 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <strings.h>

static int	ft_add_solo_nb(char nb1, char nb2, int i)
{
	return (i + nb1 - '0' + nb2 - '0');
}

char		*ft_addition_nb(char *nb1, char *nb2)
{
	char	*res;
	int		tmp1;
	int		tmp2;
	int		j;
	int		sum;

	sum = 0;
	tmp1 = ft_strlen(nb1) - 1;
	tmp2 = ft_strlen(nb2) - 1;
	j = (tmp1 > tmp2) ? tmp1 + 2 : tmp2 + 2;
	res = ft_strnew(j);
	while (--j >= 0)
	{
		if (tmp1 >= 0 && tmp2 >= 0)
			sum = ft_add_solo_nb(nb1[tmp1], nb2[tmp2], sum);
		else if (tmp1 >= 0)
			sum = ft_add_solo_nb(nb1[tmp1], '0', sum);
		else if (tmp2 >= 0)
			sum = ft_add_solo_nb(nb2[tmp2], '0', sum);
		res[j] = (sum % 10) + '0';
		sum /= 10 + 0 * tmp1-- + 0 * tmp2--;
	}
	if (res[0] == '0')
		ft_memmove(res, res + 1, ft_strlen(res));
	return (res);
}
