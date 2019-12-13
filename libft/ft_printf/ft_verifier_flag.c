/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifier_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:17:32 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/21 15:15:54 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_verifier_option(const char format, t_flag *flag)
{
	if (!flag->prec && !flag->taille)
	{
		if (format == '-')
		{
			flag->moin = 1;
			flag->zero = 0;
		}
		if (format == '+')
		{
			flag->plus = 1;
			flag->espace = 0;
		}
		if (format == '#')
			flag->htag = 1;
		if (format == '0' && !flag->moin && flag->tmp != '.')
			flag->tmp = '0';
		if (ft_isdigit(format) && flag->tmp == '0')
		{
			flag->zero = flag->zero * 10 + (format - '0');
			flag->zerof = flag->zerof * 10 + (format - '0');
		}
		if (format == ' ' && !flag->plus)
			flag->espace = 1;
	}
	return (0);
}

int	ft_verifier_field_prec(const char format, t_flag *flag, va_list list)
{
	if (!flag->taille)
	{
		if (ft_isdigit(format) && flag->tmp != '.')
			flag->field = flag->field * 10 + (format - '0');
		else if (format == '*' && flag->tmp != '.')
			flag->field = va_arg(list, int);
		if (ft_isdigit(format) && flag->tmp == '.')
		{
			flag->prec = flag->prec * 10 + (format - '0');
			flag->zero = 0;
		}
		else if (format == '*' && flag->tmp == '.')
		{
			flag->prec = va_arg(list, int);
			flag->zero = 0;
		}
		if (flag->field < 0)
		{
			flag->field *= -1;
			flag->moin = 1;
		}
	}
	return (0);
}

int	ft_verifier_flag(const char format, t_flag *flag, va_list list)
{
	if (format == '.')
	{
		flag->tmp = '.';
		flag->zero = 0;
	}
	if (!flag->tmp || flag->tmp == '0')
		ft_verifier_option(format, flag);
	ft_verifier_field_prec(format, flag, list);
	if (format == 'l' && flag->taille <= 2)
		flag->taille += 1;
	if (format == 'h' && (flag->taille == 0 || flag->taille >= 3))
		flag->taille += 3;
	if (format == 'j' && !flag->taille)
		flag->taille = 5;
	if (format == 'z' && !flag->taille)
		flag->taille = 9;
	if (format == 'L')
		flag->taille = 7;
	ft_type_conversion(format, flag, list);
	return (0);
}
