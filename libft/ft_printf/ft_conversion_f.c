/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:51:38 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 15:34:38 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_zero_bin(long mant, int len)
{
	char	*res;
	char	*bin;
	int		j;
	char	*str;

	str = ft_itoa_base(mant, 2);
	j = len - ft_strlen(str);
	res = ft_strnew(j);
	ft_memset(res, '0', j);
	bin = ft_strjoin(res, str);
	free(res);
	free(str);
	return (bin);
}

char	*ft_get_man_value(char *str)
{
	int		i;
	char	*res;
	char	*pow;
	char	*tmp;

	i = -1;
	res = ft_strdup("0");
	while (str[++i])
	{
		pow = ft_puissance_nb("5", i + 1);
		if (str[i] == '1')
		{
			tmp = res;
			res = ft_addition_nb(res, pow);
			free(tmp);
		}
		if (str[i + 1])
		{
			tmp = res;
			res = ft_multiple_nb(res, "10");
			free(tmp);
		}
		free(pow);
	}
	return (res);
}

char	*ft_get_float_value(int exp, char *str, t_flag *flag, int len)
{
	char	*res;
	char	*pow;
	int		exponent;

	if (exp >= 1023)
	{
		exponent = exp - 1023;
		pow = ft_puissance_deux(exponent);
		res = ft_multiple_nb(str, pow);
		flag->virgule = ft_strlen(res) - len;
	}
	if (exp < 1023)
	{
		exponent = 1023 - exp;
		pow = ft_puissance_nb("5", exponent);
		res = ft_multiple_nb(str, pow);
		flag->virgule = ft_strlen(res) - len - exponent;
	}
	free(pow);
	return (res);
}

void	ft_traitement_float(t_flag *flag, char *str, int sign)
{
	char	*res;
	char	*tmp;
	char	*nbr;

	flag->signe = sign;
	if (flag->tmp != '.' && !flag->prec)
		flag->prec = 6;
	nbr = ft_add_prec_nb(str, flag->prec + flag->virgule);
	if (flag->virgule <= 0)
		res = ft_add_zero_nb(nbr, flag);
	else
		res = ft_strdup(nbr);
	tmp = ft_rounding_nb(res, flag->prec + flag->virgule);
	ft_print_float(tmp, flag);
	free(res);
	free(tmp);
	free(nbr);
}

int		ft_conversion_f(t_flag *flag, va_list list)
{
	char	*str;
	char	*tmp;
	char	*tot;
	char	*pow;
	char	*res;

	num.f = va_arg(list, double);
	str = ft_add_zero_bin(num.flt.man, 52);
	tmp = ft_get_man_value(str);
	pow = ft_puissance_nb("10", ft_strlen(tmp));
	res = ft_addition_nb(tmp, pow);
	tot = ft_get_float_value(num.flt.exp, res, flag, ft_strlen(tmp));
	if (ft_trait_special_float(num.flt.sign, num.flt.exp, str, flag))
		ft_traitement_float(flag, tot, num.flt.sign);
	free(str);
	free(tmp);
	free(tot);
	free(res);
	free(pow);
	return (0);
}
