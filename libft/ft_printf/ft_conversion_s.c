/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:01:43 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/15 15:39:20 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str_size(char *str, int size)
{
	char	*ptr;

	ptr = ft_strsub(str, 0, size);
	ft_putstr(ptr);
	free(ptr);
	return (size);
}

int	ft_conversion_s(t_flag *flag, va_list list)
{
	char	*str;
	int		len;
	char	*tmp;

	if (flag->taille == 1 || flag->taille == 2)
		ft_conversion_ls(flag, list);
	else
	{
		tmp = va_arg(list, char*);
		str = ((tmp) ? ft_strdup(tmp) : ft_strdup("(null)"));
		flag->prec = (flag->prec > (int)ft_strlen(str)) ? ft_strlen(str) :
			flag->prec;
		len = (flag->tmp == '.' && (int)ft_strlen(str)) ? flag->prec :
			(int)ft_strlen(str);
		if (!flag->moin && flag->field)
			flag->print += ft_print_size(' ', flag->field - len);
		flag->print += ft_print_str_size(str, len);
		if (flag->moin && flag->field)
			flag->print += ft_print_size(' ', flag->field - len);
		free(str);
	}
	return (0);
}

int	ft_traitement_null(t_flag *flag)
{
	int		len;
	char	*str;

	str = ft_strdup("(null)");
	len = (flag->tmp == '.' && (int)ft_strlen(str)) ? flag->prec :
		(int)ft_strlen(str);
	if (!flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - len);
	flag->print += ft_print_str_size(str, len);
	if (flag->moin && flag->field)
		flag->print += ft_print_size(' ', flag->field - len);
	free(str);
	return (0);
}
