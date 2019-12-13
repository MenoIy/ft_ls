/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:05:34 by kdaou             #+#    #+#             */
/*   Updated: 2019/02/18 14:18:55 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include "stdarg.h"
# include <limits.h>

typedef struct		s_dbl
{
	unsigned long	man : 63;
	unsigned int	norm : 1;
	unsigned int	exp : 15;
	unsigned int	sign : 1;
}					t_dbl;

union				u_lnum
{
	t_dbl			dbl;
	long double		f;
}					lnum;

typedef struct		s_flt
{
	unsigned long	man : 52;
	unsigned int	exp : 11;
	unsigned int	sign : 1;
}					t_flt;

union				u_num
{
	t_flt			flt;
	double			f;
}					num;

typedef struct		s_flag
{
	int				moin;
	int				plus;
	int				htag;
	int				zero;
	int				espace;
	int				field;
	int				prec;
	int				taille;
	char			tmp;
	char			tmp1;
	char			type;
	int				signe;
	int				print;
	int				virgule;
	int				zerof;
}					t_flag;

int					ft_printf(const char *format, ...);
t_flag				*ft_creat_flag_env(void);
void				ft_ini_flags(t_flag *flag);
int					ft_verifier_flag(const char format, t_flag *flag,
					va_list list);
int					ft_print_type_d(va_list list, t_flag *flag);
int					ft_type_conversion(const char format, t_flag *flag,
					va_list list);
int					ft_type_conversion_2(const char format, t_flag *flag,
					va_list list);
int					ft_type_conversion_3(const char format, t_flag *flag,
					va_list list);
int					ft_type_conversion_4(const char format, t_flag *flag,
					va_list list);
int					ft_conversion_d(t_flag *flag, va_list list);
int					ft_conversion_c(t_flag *flag, va_list list);
int					ft_conversion_s(t_flag *flag, va_list list);
int					ft_conversion_p(t_flag *flag, va_list list);
int					ft_conversion_x(t_flag *flag, va_list list);
int					ft_conversion_b(t_flag *flag, va_list list);
int					ft_conversion_xx(t_flag *flag, va_list list);
int					ft_conversion_u(t_flag *flag, va_list list);
int					ft_conversion_o(t_flag *flag, va_list list);
int					ft_conversion_f(t_flag *flag, va_list list);
int					ft_conversion_lf(t_flag *flag, va_list list);
int					ft_conversion_ls(t_flag *flag, va_list list);
int					ft_print_size(char c, int size);
int					ft_print_str_size(char *str, int size);

uintmax_t			ft_get_taille_d(va_list list, t_flag *flag);
uintmax_t			ft_get_taille_x(va_list list, t_flag *flag);
uintmax_t			ft_get_taille_o(va_list list, t_flag *flag);
uintmax_t			ft_get_taille_u(va_list list, t_flag *flag);
uintmax_t			ft_get_taille_uu(va_list list, t_flag *flag);
uintmax_t			ft_get_taille_oo(va_list list, t_flag *flag);
uintmax_t			ft_get_taille_dd(va_list list, t_flag *flag);

char				*ft_puissance_nb(char *nb, int puissance);
char				*ft_addition_nb(char *nb1, char *nb2);
char				*ft_puissance_deux(int puissance);
char				*ft_multiple_nb(char *nb1, char *nb2);
char				*ft_add_zero_bin(long man, int len);
char				*ft_get_man_value(char *str);
char				*ft_get_float_value(int exp, char *str, t_flag *flag,
					int len);
char				*ft_rounding_nb(char *str, int prec);
char				*ft_add_zero_nb(char *nb, t_flag *flag);
char				*ft_add_prec_nb(char *nb, int prec);
void				ft_print_float(char *nbr, t_flag *flag);
int					ft_trait_special_float(int sign, int exp, char *man,
					t_flag *flag);
void				ft_print_special_float(char *nbr, t_flag *flag,
					int sign);
char				*ft_get_double_value(int exp, char *str, t_flag *flag,
					int len);
void				ft_traitement_float(t_flag *flag, char *str, int sign);

void				ft_traitement_unicode_11(t_flag *flag, unsigned int c);
void				ft_traitement_unicode_16(t_flag *flag, unsigned int c);
void				ft_traitement_unicode_21(t_flag *flag, unsigned int c);
void				ft_traitement_c(t_flag *flag, unsigned int c);
int					ft_conversion_unicode(t_flag *flag, va_list list);
int					ft_traitement_null(t_flag *flag);
int					ft_size_str_wchar(wchar_t *str);

#endif
