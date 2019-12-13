/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_ls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:34:24 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/15 15:38:16 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstrlen(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_print_str_unicode(wchar_t *str, int size, t_flag *flag)
{
	unsigned int	c;
	int				i;

	i = 0;
	flag->field = 0;
	flag->prec = 0;
	while (i < size)
	{
		c = str[i];
		if (c < 128)
			ft_traitement_c(flag, c);
		else if (c < 2048)
			ft_traitement_unicode_11(flag, c);
		else if (c > 55295 && c < 63744)
			return (0);
		else if (c < 65536)
			ft_traitement_unicode_16(flag, c);
		else if (c < 2097152)
			ft_traitement_unicode_21(flag, c);
		i++;
	}
	return (0);
}

int		ft_size_str_wchar(wchar_t *str)
{
	int				i;
	int				size;
	unsigned int	c;

	i = 0;
	size = 0;
	while (str[i])
	{
		c = str[i];
		if (c < 128)
			size += 1;
		else if (c < 2048)
			size += 2;
		else if (c > 55295 && c < 63744)
			size += 0;
		else if (c < 65536)
			size += 3;
		else if (c < 2097152)
			size += 4;
		i++;
	}
	return (size);
}

int		ft_conversion_ls(t_flag *flag, va_list list)
{
	int		len;
	wchar_t	*tmp;
	int		prec;
	int		field;

	field = flag->field;
	prec = flag->prec;
	tmp = va_arg(list, wchar_t*);
	if (!tmp)
		ft_traitement_null(flag);
	else
	{
		prec = ((prec > (int)ft_wstrlen(tmp)) ? (int)ft_wstrlen(tmp) :
			prec);
		len = ((flag->tmp == '.' && ft_wstrlen(tmp) && prec) ? prec :
			(int)ft_wstrlen(tmp));
		if (!flag->moin && field)
			flag->print += ft_print_size(' ', field - ft_size_str_wchar(tmp));
		flag->print += ft_print_str_unicode(tmp, len, flag);
		if (flag->moin && field)
			flag->print += ft_print_size(' ', field - ft_size_str_wchar(tmp));
	}
	return (0);
}
