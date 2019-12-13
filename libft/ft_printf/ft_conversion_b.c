/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:43:54 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/15 15:53:33 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_b(t_flag *flag, va_list list)
{
	intmax_t	bin;
	char		*str;
	int			len;

	bin = (intmax_t)va_arg(list, intmax_t);
	str = ft_itoa_base(bin, 2);
	len = ((!flag->prec && !bin && flag->tmp == '.') ? 0 : ft_strlen(str));
	if (!flag->prec && !bin)
		flag->htag = 0;
	flag->prec = (flag->prec > len ? flag->prec - len : 0);
	if (!flag->moin && flag->field && !flag->zero)
		flag->print += ft_print_size(' ', (flag->field -
					flag->prec - len - flag->htag * 2));
	if (flag->htag && bin)
		flag->print += ft_print_str_size("0b", 2);
	flag->print += ft_print_size('0', (flag->zero - len - 2 * flag->htag));
	flag->print += ft_print_size('0', flag->prec);
	flag->print += ft_print_str_size(str, len);
	if (flag->moin && flag->field)
		flag->print += ft_print_size(' ', (flag->field -
					flag->prec - len - flag->htag * 2));
	free(str);
	return (0);
}
