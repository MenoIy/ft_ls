/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_taille_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:17:34 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 14:22:29 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_get_taille_uu(va_list list, t_flag *flag)
{
	uintmax_t	nbr;

	nbr = 0;
	if (flag->taille == 1)
		nbr = va_arg(list, unsigned long long int);
	else if (flag->taille == 9)
		nbr = va_arg(list, ssize_t);
	else if (flag->taille == 5)
		nbr = va_arg(list, uintmax_t);
	else
		nbr = va_arg(list, unsigned long int);
	return (nbr);
}

uintmax_t	ft_get_taille_dd(va_list list, t_flag *flag)
{
	intmax_t	nbr;

	nbr = 0;
	if (flag->taille == 1)
		nbr = va_arg(list, long long int);
	else if (flag->taille == 9)
		nbr = va_arg(list, ssize_t);
	else if (flag->taille == 5)
		nbr = va_arg(list, intmax_t);
	else
		nbr = va_arg(list, long int);
	return (nbr);
}
