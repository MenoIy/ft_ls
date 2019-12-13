/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:46:47 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 22:01:07 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ini_flags(t_flag *flag)
{
	flag->moin = 0;
	flag->plus = 0;
	flag->htag = 0;
	flag->zero = 0;
	flag->espace = 0;
	flag->field = 0;
	flag->prec = 0;
	flag->taille = 0;
	flag->tmp = '\0';
	flag->type = '\0';
	flag->signe = 0;
	flag->virgule = 0;
	flag->zerof = 0;
	flag->tmp1 = '\0';
}
