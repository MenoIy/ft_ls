/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_lf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:23:25 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 15:36:06 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_double_value(int exp, char *str, t_flag *flag, int len)
{
	char	*res;
	char	*pow;
	int		exponent;

	if (exp >= 16383)
	{
		exponent = exp - 16383;
		pow = ft_puissance_deux(exponent);
		res = ft_multiple_nb(str, pow);
		flag->virgule = ft_strlen(res) - len;
	}
	if (exp < 16383)
	{
		exponent = 16383 - exp;
		pow = ft_puissance_nb("5", exponent);
		res = ft_multiple_nb(str, pow);
		flag->virgule = ft_strlen(res) - len - exponent;
	}
	free(pow);
	return (res);
}

int		ft_conversion_lf(t_flag *flag, va_list list)
{
	char	*str;
	char	*tmp;
	char	*tot;
	char	*pow;
	char	*res;

	lnum.f = va_arg(list, long double);
	str = ft_add_zero_bin(lnum.dbl.man, 63);
	tmp = ft_get_man_value(str);
	if (lnum.dbl.norm == 1)
		pow = ft_puissance_nb("10", ft_strlen(tmp));
	else
		pow = ft_strdup("0");
	res = ft_addition_nb(tmp, pow);
	tot = ft_get_double_value(lnum.dbl.exp, res, flag, ft_strlen(tmp));
	if (ft_trait_special_float(lnum.dbl.sign, lnum.dbl.exp, str, flag))
		ft_traitement_float(flag, tot, lnum.dbl.sign);
	free(str);
	free(tmp);
	free(tot);
	free(res);
	free(pow);
	return (0);
}
