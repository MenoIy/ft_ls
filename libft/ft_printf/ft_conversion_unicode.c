/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_unicode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:09:21 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 20:39:16 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_traitement_c(t_flag *flag, unsigned int c)
{
	if (!flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - 1);
	flag->print += ft_print_size(c, 1);
	if (flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - 1);
}

int		ft_conversion_unicode(t_flag *flag, va_list list)
{
	unsigned int c;

	c = va_arg(list, unsigned int);
	if (c < 128)
		ft_traitement_c(flag, c);
	else if (c < 2048)
		ft_traitement_unicode_11(flag, c);
	else if (c > 55295 && c < 63744)
		return (0);
	else if (c < 65536)
		ft_traitement_unicode_16(flag, c);
	else if (c < 2097152)
		ft_traitement_unicode_21(flag, c);
	return (0);
}
