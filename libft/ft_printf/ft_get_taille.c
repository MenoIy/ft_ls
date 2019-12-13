/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_taille.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:05:49 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 14:21:09 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_get_taille_d(va_list list, t_flag *flag)
{
	intmax_t	nbr;

	nbr = 0;
	if (flag->taille == 3)
		nbr = (short)va_arg(list, int);
	else if (flag->taille == 6)
		nbr = (char)va_arg(list, int);
	else if (flag->taille == 1)
		nbr = va_arg(list, long int);
	else if (flag->taille == 2)
		nbr = va_arg(list, long long int);
	else if (flag->taille == 9)
		nbr = va_arg(list, ssize_t);
	else if (flag->taille == 5)
		nbr = va_arg(list, uintmax_t);
	else
		nbr = va_arg(list, int);
	return (nbr);
}

uintmax_t	ft_get_taille_u(va_list list, t_flag *flag)
{
	uintmax_t	nbr;

	nbr = 0;
	if (flag->taille == 3)
		nbr = (unsigned short)va_arg(list, unsigned int);
	else if (flag->taille == 6)
		nbr = (unsigned char)va_arg(list, unsigned int);
	else if (flag->taille == 1)
		nbr = va_arg(list, unsigned long);
	else if (flag->taille == 2)
		nbr = va_arg(list, unsigned long long int);
	else if (flag->taille == 9)
		nbr = va_arg(list, ssize_t);
	else if (flag->taille == 5)
		nbr = va_arg(list, uintmax_t);
	else
		nbr = va_arg(list, unsigned int);
	return (nbr);
}

uintmax_t	ft_get_taille_x(va_list list, t_flag *flag)
{
	intmax_t	nbr;

	nbr = 0;
	if (flag->taille == 3)
		nbr = (unsigned short)va_arg(list, unsigned int);
	else if (flag->taille == 6)
		nbr = (unsigned char)va_arg(list, unsigned int);
	else if (flag->taille == 1)
		nbr = va_arg(list, unsigned long int);
	else if (flag->taille == 2)
		nbr = va_arg(list, unsigned long long int);
	else if (flag->taille == 9)
		nbr = va_arg(list, ssize_t);
	else if (flag->taille == 5)
		nbr = va_arg(list, uintmax_t);
	else
		nbr = va_arg(list, unsigned int);
	return (nbr);
}

uintmax_t	ft_get_taille_o(va_list list, t_flag *flag)
{
	intmax_t	nbr;

	nbr = 0;
	if (flag->taille == 3)
		nbr = (unsigned short)va_arg(list, unsigned int);
	else if (flag->taille == 6)
		nbr = (unsigned char)va_arg(list, unsigned int);
	else if (flag->taille == 1)
		nbr = va_arg(list, unsigned long int);
	else if (flag->taille == 2)
		nbr = va_arg(list, unsigned long long int);
	else if (flag->taille == 9)
		nbr = va_arg(list, ssize_t);
	else if (flag->taille == 5)
		nbr = va_arg(list, uintmax_t);
	else
		nbr = va_arg(list, unsigned int);
	return (nbr);
}

uintmax_t	ft_get_taille_oo(va_list list, t_flag *flag)
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
