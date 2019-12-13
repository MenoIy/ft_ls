/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:41:19 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 14:40:05 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_float(char *nbr, t_flag *flag)
{
	int t;
	int i;

	i = -1;
	flag->espace = (flag->signe ? 0 : flag->espace);
	flag->print += ft_print_size(' ', flag->espace);
	flag->plus = (flag->signe ? 0 : flag->plus);
	t = ((flag->virgule == (int)ft_strlen(nbr) && !flag->htag) ? 0 : 1);
	t += ft_strlen(nbr) + flag->plus + flag->signe + flag->espace;
	if (!flag->moin && flag->field && !flag->zero)
		flag->print += ft_print_size(' ', flag->field - t - flag->zerof);
	flag->print += ft_print_size('-', flag->signe);
	flag->print += ft_print_size('+', flag->plus);
	flag->print += ft_print_size('0', flag->zerof - t);
	while (nbr[++i])
	{
		flag->print += ft_print_size((nbr[i]), 1);
		if (i + 1 == flag->virgule && nbr[i + 1] != '\0')
			flag->print += ft_print_size('.', 1);
	}
	if (!flag->prec && flag->tmp == '.' && flag->htag)
		flag->print += ft_print_size('.', 1);
	if (flag->moin && flag->field && !flag->zero)
		flag->print += ft_print_size(' ', flag->field - t - flag->zerof);
}
