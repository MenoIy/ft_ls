/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:32:05 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/15 15:47:07 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_o(t_flag *flag, va_list list)
{
	uintmax_t	hex;
	char		*str;
	int			len;

	hex = (flag->type == 'O') ? ft_get_taille_oo(list, flag) :
		ft_get_taille_o(list, flag);
	str = ft_itoa_base(hex, 8);
	len = ((!flag->prec && !hex && flag->tmp == '.') ? 0 : ft_strlen(str));
	flag->htag = (hex || (!flag->prec && flag->tmp == '.') ? flag->htag : 0);
	flag->prec = (flag->prec > len ? flag->prec - len - flag->htag : 0);
	if (!flag->moin && flag->field && !flag->zero)
		flag->print += ft_print_size(' ', (flag->field -
					flag->prec - len - flag->htag));
	flag->print += ft_print_str_size("0", flag->htag);
	flag->print += ft_print_size('0', (flag->zero - len - flag->htag));
	flag->print += ft_print_size('0', flag->prec);
	flag->print += ft_print_str_size(str, len);
	if (flag->moin && flag->field)
		flag->print += ft_print_size(' ', (flag->field -
					flag->prec - len - flag->htag));
	free(str);
	return (0);
}
