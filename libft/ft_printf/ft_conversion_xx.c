/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_xx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:57:46 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 14:14:43 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_toupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (0);
}

int	ft_conversion_xx(t_flag *flag, va_list list)
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
		flag->print += ft_print_str_size("0X", 2);
	flag->print += ft_print_size('0', (flag->zero - len - 2 * flag->htag));
	flag->print += ft_print_size('0', flag->prec);
	ft_str_toupper(str);
	if (!(!flag->prec && !hex && flag->tmp == '.'))
		flag->print += ft_print_str_size(str, len);
	if (flag->moin && flag->field)
		flag->print += ft_print_size(' ', (flag->field -
					flag->prec - len - flag->htag * 2));
	free(str);
	return (0);
}
