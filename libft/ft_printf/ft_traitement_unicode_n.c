/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_unicode_n.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:29:40 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 22:01:56 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_traitement_unicode_11(t_flag *flag, unsigned int c)
{
	unsigned int	n;

	if (!flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - 2);
	n = (c >> 6) + 192;
	write(1, &n, 1);
	n = (c & 63) + 128;
	write(1, &n, 1);
	flag->print += 2;
	if (flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - 2);
}

void	ft_traitement_unicode_16(t_flag *flag, unsigned int c)
{
	unsigned int n;

	if (!flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - 3);
	n = (c >> 12) + 224;
	write(1, &n, 1);
	n = ((c >> 6) & 63) + 128;
	write(1, &n, 1);
	n = (c & 63) + 128;
	write(1, &n, 1);
	flag->print += 3;
	if (flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - 3);
}

void	ft_traitement_unicode_21(t_flag *flag, unsigned int c)
{
	unsigned int n;

	if (!flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - 4);
	n = (c >> 18) + 240;
	write(1, &n, 1);
	n = ((c >> 12) & 63) + 128;
	write(1, &n, 1);
	n = ((c >> 6) & 63) + 128;
	write(1, &n, 1);
	n = (c & 63) + 128;
	write(1, &n, 1);
	flag->print += 4;
	if (flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - 4);
}
