/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:14:46 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/24 14:10:03 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_del_flag(t_flag **flag)
{
	free(*flag);
	*flag = NULL;
}

int		ft_traitement_printf(const char *format, t_flag *flag, va_list list)
{
	int	tmp;

	tmp = 0;
	while (*format)
	{
		if (*format == '%' && flag->type)
		{
			ft_ini_flags(flag);
			tmp = 0;
		}
		if (*format == '%' && !tmp)
		{
			tmp = 1;
			format += 1;
		}
		if (!flag->type && tmp)
			ft_verifier_flag(*(format), flag, list);
		else
			flag->print += ft_print_size(*format, 1);
		format += 1;
	}
	return (flag->print);
}

int		ft_printf(const char *format, ...)
{
	va_list	list;
	t_flag	*flag;
	int		n;

	if (format == NULL)
		return (-1);
	flag = ft_creat_flag_env();
	va_start(list, format);
	n = ft_traitement_printf(format, flag, list);
	va_end(list);
	ft_del_flag(&flag);
	return (n);
}
