/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:31:33 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/15 15:45:47 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_p(t_flag *flag, va_list list)
{
	unsigned long int	hex;
	char				*str;
	int					len;

	hex = (unsigned long int)va_arg(list, char *);
	str = ft_itoa_base(hex, 16);
	len = ft_strlen(str);
	if (!flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - len - 2);
	flag->print += ft_print_str_size("0x", 2);
	flag->print += ft_print_str_size(str, len);
	if (flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - len - 2);
	free(str);
	return (0);
}
