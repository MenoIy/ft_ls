/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:51:15 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/14 23:08:20 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*ft_creat_flag_env(void)
{
	t_flag	*flag;

	if (!(flag = (t_flag *)malloc(sizeof(t_flag))))
		return (NULL);
	flag->moin = 0;
	flag->plus = 0;
	flag->htag = 0;
	flag->zero = 0;
	flag->espace = 0;
	flag->field = 0;
	flag->prec = 0;
	flag->taille = 0;
	flag->tmp = '\0';
	flag->tmp1 = '\0';
	flag->type = '\0';
	flag->print = 0;
	flag->signe = 0;
	flag->virgule = 0;
	flag->zerof = 0;
	return (flag);
}
