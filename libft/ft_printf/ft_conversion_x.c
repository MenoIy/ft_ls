/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:03:48 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/24 14:16:19 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_x(t_flag *flag, va_list list)
{
	uintmax_t	hex;
	char		*str;
	int			len;

	hex = ft_get_taille_x(list, flag);
	str = ft_itoa_base(hex, 16);
	len = ((!flag->prec && !hex && flag->tmp == '.') ? 0 : ft_strlen(str));
	if (!flag->prec && !hex)
		flag->htag = 0;
	flag->prec = (flag->prec > len ? flag->prec - len : 0);
	if (!flag->moin && flag->field && !flag->zero)
		flag->print += ft_print_size(' ', (flag->field -
					flag->prec - len - flag->htag * 2));
	if (flag->htag && hex)
		flag->print += ft_print_str_size("0x", 2);
	flag->print += ft_print_size('0', (flag->zero - len - 2 * flag->htag));
	flag->print += ft_print_size('0', flag->prec);
	flag->print += ft_print_str_size(str, len);
	if (flag->moin && flag->field)
		flag->print += ft_print_size(' ', (flag->field -
					flag->prec - len - flag->htag * 2));
	free(str);
	return (0);
}
