/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:39:33 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/15 16:11:39 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_100(t_flag *flag)
{
	if (flag->moin)
		flag->zerof = 0;
	if (!flag->moin && flag->field && !flag->zerof)
		flag->print += ft_print_size(' ', flag->field - 1);
	flag->print += ft_print_size('0', flag->zerof - 1);
	flag->print += ft_print_size('%', 1);
	if (flag->moin && flag->field && !flag->zerof)
		flag->print += ft_print_size(' ', flag->field - 1);
	return (0);
}

int	ft_type_conversion(const char format, t_flag *flag, va_list list)
{
	if (format == 'd' || format == 'i')
	{
		ft_conversion_d(flag, list);
		flag->type = format;
	}
	if (format == 'c')
	{
		flag->type = 'c';
		ft_conversion_c(flag, list);
	}
	if (format == 's')
	{
		flag->type = 's';
		ft_conversion_s(flag, list);
	}
	if (format == '%')
	{
		flag->type = '%';
		ft_conversion_100(flag);
	}
	ft_type_conversion_2(format, flag, list);
	ft_type_conversion_3(format, flag, list);
	ft_type_conversion_4(format, flag, list);
	return (0);
}

int	ft_type_conversion_2(const char format, t_flag *flag, va_list list)
{
	if (format == 'D')
	{
		flag->type = 'D';
		ft_conversion_d(flag, list);
	}
	else if (format == 'f' || format == 'F')
	{
		flag->type = 'f';
		if (flag->taille == 7)
			ft_conversion_lf(flag, list);
		else
			ft_conversion_f(flag, list);
	}
	else if (format == 'C')
	{
		flag->type = 'C';
		ft_conversion_unicode(flag, list);
	}
	else if (format == 'S')
	{
		flag->type = 'S';
		ft_conversion_ls(flag, list);
	}
	return (0);
}

int	ft_type_conversion_3(const char format, t_flag *flag, va_list list)
{
	if (format == 'u')
	{
		flag->type = 'u';
		ft_conversion_u(flag, list);
	}
	if (format == 'o')
	{
		flag->type = 'o';
		ft_conversion_o(flag, list);
	}
	if (format == 'U')
	{
		flag->type = 'u';
		ft_conversion_u(flag, list);
	}
	if (format == 'O')
	{
		flag->type = 'O';
		ft_conversion_o(flag, list);
	}
	return (0);
}

int	ft_type_conversion_4(const char format, t_flag *flag, va_list list)
{
	if (format == 'p')
	{
		flag->type = 'p';
		ft_conversion_p(flag, list);
	}
	if (format == 'x')
	{
		flag->type = 'x';
		ft_conversion_x(flag, list);
	}
	if (format == 'X')
	{
		flag->type = 'X';
		ft_conversion_xx(flag, list);
	}
	if (format == 'b')
	{
		flag->type = 'b';
		ft_conversion_b(flag, list);
	}
	return (0);
}
