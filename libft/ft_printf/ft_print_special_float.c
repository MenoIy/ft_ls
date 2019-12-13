/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_special_float.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:25:54 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 14:40:55 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_special_float(char *nbr, t_flag *flag, int sign)
{
	int len;

	len = ft_strlen(nbr);
	flag->plus = sign == 1 ? 0 : flag->plus;
	if (!ft_strcmp(nbr, "inf"))
		flag->signe = sign;
	if (!flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - len - flag->signe);
	if (!ft_strcmp(nbr, "inf"))
	{
		flag->print += ft_print_size(' ', flag->espace);
		flag->print += ft_print_size('+', flag->plus);
		flag->print += ft_print_size('-', sign);
	}
	flag->print += ft_print_str_size(nbr, len);
	if (flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - len - flag->signe);
}

int		ft_trait_special_float(int sign, int exp, char *man, t_flag *flag)
{
	int i;

	i = 0;
	if (exp == 2047)
	{
		while (man[i])
		{
			if (man[i] == '1')
			{
				ft_print_special_float("nan", flag, sign);
				return (0);
			}
			i++;
		}
		ft_print_special_float("inf", flag, sign);
		return (0);
	}
	return (1);
}
