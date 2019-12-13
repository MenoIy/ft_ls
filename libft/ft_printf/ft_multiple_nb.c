/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:45:31 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 14:39:11 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_multiple_solo_nb(char *nb1, char nb2, int c)
{
	char	*res;
	int		j;
	int		i;
	int		sum;

	sum = 0;
	i = ft_strlen(nb1) - 1;
	j = ft_strlen(nb1) + c + 1;
	res = ft_strnew(j + 1);
	while (--j >= 0)
	{
		while (c > 0)
		{
			res[j] = '0';
			j--;
			c--;
		}
		if (i >= 0)
			sum = (nb1[i--] - '0') * (nb2 - '0') + sum;
		res[j] = (sum % 10) + '0';
		sum /= 10;
	}
	if (res[0] == '0')
		ft_memmove(res, (res + 1), ft_strlen(res));
	return (res);
}

char	*ft_multiple_nb(char *nb1, char *nb2)
{
	char	*res;
	int		j;
	char	*sum;
	char	*mltp;
	int		c;

	c = 0;
	j = ft_strlen(nb2);
	sum = ft_strdup("0");
	while (--j >= 0)
	{
		res = sum;
		if (nb2[j] != '0')
			mltp = ft_multiple_solo_nb(nb1, nb2[j], c);
		else
			mltp = ft_strdup("0");
		sum = ft_addition_nb(mltp, sum);
		free(mltp);
		free(res);
		c++;
	}
	return (sum);
}
