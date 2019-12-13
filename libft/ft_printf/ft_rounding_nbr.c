/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounding_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 21:15:12 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/15 15:39:54 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_verifier_rounding(char *str, char *aff, int prec)
{
	char	*res;
	int		i;

	i = prec;
	while (str[++i])
	{
		if (str[i] != '0')
		{
			res = ft_addition_nb("1", aff);
			break ;
		}
	}
	if (str[i] == '\0' && (str[prec - 1] - '0') % 2)
		res = ft_addition_nb("1", aff);
	if (str[i] == '\0' && (str[prec - 1] - '0') % 2 == 0)
		res = ft_strdup(aff);
	return (res);
}

char	*ft_rounding_nb(char *str, int prec)
{
	char	*res;
	char	*aff;

	aff = ft_strsub(str, 0, prec);
	if (str[prec] > '5')
		res = ft_addition_nb("1", aff);
	if (str[prec] == '5')
		res = ft_verifier_rounding(str, aff, prec);
	if (str[prec] < '5')
		res = ft_strdup(aff);
	free(aff);
	return (res);
}
