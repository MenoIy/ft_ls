/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:33:00 by kdaou             #+#    #+#             */
/*   Updated: 2019/03/12 15:36:06 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				ft_print_illegal(char c, t_ls **ls)
{
	ft_del_struct_ls(ls);
	ft_printf("./ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ./ft_ls ");
	ft_printf("[-laRrt1SfucAT] [file ...]\n");
	exit(1);
}

static unsigned long	ft_get_indice(char c, t_ls **ls)
{
	char	*str;
	int		i;

	i = 0;
	str = "laRrt1SfucAT";
	while (str[i])
	{
		if (str[i] == c)
			return (1 << (i + 1));
		i++;
	}
	ft_print_illegal(c, ls);
	return (0);
}

static unsigned long	ft_read_option(char *str,
						unsigned long option, t_ls **ls)
{
	int	i;
	int indice;

	i = 1;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (!str[i + 1])
				return (option | 1);
			else
				ft_print_illegal('-', ls);
		}
		indice = ft_get_indice(str[i], ls);
		option -= (option & SL && indice == ONE) ? SL : 0;
		if ((option & SC) && indice == SU)
			option -= SC;
		else if ((option & SU) && indice == SC)
			option -= SU;
		option -= (option & SA && option & BA) ? BA : 0;
		option = option | indice;
		i++;
	}
	return (option);
}

int						main(int argc, char **argv)
{
	int				i;
	int				tmp;
	t_ls			*ls;

	tmp = 0;
	i = 0;
	ls = ft_new_struct_ls();
	ls->first = 1;
	while (++i < argc)
	{
		if (!(ls->option & 1) && argv[i][0] == '-' && argv[i][1])
			ls->option = ft_read_option(argv[i], ls->option, &ls);
		else
		{
			ft_traitement_ls(argv[i], &ls, argv[i]);
			ls->option = (ls->option | 1) + tmp++ * 0;
		}
	}
	if (argc < 2 || !tmp)
		ft_traitement_ls(".", &ls, ".");
	ft_sorting_ls(&ls);
	ft_gestion_ls(ls);
	if (!(ls->option & BR))
		ft_del_struct_ls(&ls);
	return (0);
}
