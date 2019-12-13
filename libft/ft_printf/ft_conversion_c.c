/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 09:49:57 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/15 15:51:43 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_c(t_flag *flag, va_list list)
{
	char	c;

	if (flag->taille == 1 || flag->taille == 2)
		ft_conversion_unicode(flag, list);
	else
	{
		c = va_arg(list, int);
		if (!flag->moin && flag->field)
			flag->print += ft_print_size(' ', flag->field - 1);
		flag->print += ft_print_size(c, 1);
		if (flag->moin && flag->field)
			flag->print += ft_print_size(' ', flag->field - 1);
	}
	return (0);
}
