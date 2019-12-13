/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_zer_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:38:51 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 13:40:03 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_zero_nb(char *nb, t_flag *flag)
{
	char	*str;
	char	*res;

	str = ft_strnew(-flag->virgule + 1);
	ft_memset(str, '0', -flag->virgule + 1);
	res = ft_strjoin(str, nb);
	flag->virgule = 1;
	free(str);
	return (res);
}

char	*ft_add_prec_nb(char *nb, int prec)
{
	char	*str;
	int		len;
	char	*res;

	len = prec - ft_strlen(nb);
	if (len > 0)
	{
		str = ft_strnew(len + 1);
		ft_memset(str, '0', len + 1);
		res = ft_strjoin(nb, str);
		free(str);
	}
	if (len <= 0)
		res = ft_strdup(nb);
	return (res);
}
