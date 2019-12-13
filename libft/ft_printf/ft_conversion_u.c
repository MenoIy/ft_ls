/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:00:37 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 14:12:48 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_u(t_flag *flag, va_list list)
{
	uintmax_t	n;
	int			len;

	n = (flag->type == 'U') ? ft_get_taille_uu(list, flag) :
		ft_get_taille_u(list, flag);
	len = ((n == 0 && !flag->prec && flag->tmp == '.') ? 0 :
		ft_udigitlen(n, 10));
	flag->prec = (flag->prec > len ? flag->prec - len : 0);
	if (!flag->moin && flag->field && !flag->zero)
		flag->print += ft_print_size(' ', (flag->field -
					flag->prec - len));
	flag->print += ft_print_size('0', (flag->zero - len));
	flag->print += ft_print_size('0', (flag->prec));
	if (!(!n && !(flag->prec + len) && flag->tmp == '.'))
		ft_putnbrmax(n);
	if (flag->moin && flag->field && !flag->zero)
		flag->print += ft_print_size(' ', flag->field -
				flag->prec - len);
	flag->print += len;
	return (0);
}
