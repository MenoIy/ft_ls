/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:30:59 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 22:14:37 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_size(char c, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

int	ft_conversion_d(t_flag *flag, va_list list)
{
	intmax_t	n;
	int			len;
	int			tmp;

	n = (flag->type == 'D') ? ft_get_taille_dd(list, flag)
		: ft_get_taille_d(list, flag);
	len = ((!n && !flag->prec && flag->tmp == '.') ? 0 : ft_digitlen(n, 10));
	flag->prec = (flag->prec > len ? flag->prec - len : 0);
	flag->signe = (n < 0 ? 1 : 0);
	flag->espace = ((n < 0) ? 0 : flag->espace);
	flag->print += ((n < 0) ? 0 : ft_print_size(' ', flag->espace));
	flag->plus = (n < 0 ? 0 : flag->plus);
	tmp = len + flag->plus + flag->signe + flag->espace;
	if (!flag->moin && flag->field && !flag->zero)
		flag->print += ft_print_size(' ', (flag->field - flag->prec - tmp));
	flag->print += ((n < 0) ? ft_print_size('-', 1) : 0);
	flag->print += ((n >= 0 && flag->plus) ? ft_print_size('+', 1) : 0);
	flag->print += ft_print_size('0', flag->zero - tmp);
	flag->print += ft_print_size('0', (flag->prec));
	if (!(!n && !(flag->prec + len) && flag->tmp == '.'))
		ft_putintmax(n);
	if (flag->moin && flag->field && !flag->zero)
		flag->print += ft_print_size(' ', flag->field - flag->prec - tmp);
	flag->print += len;
	return (0);
}
