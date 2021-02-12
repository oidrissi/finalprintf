/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:00:13 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 15:20:18 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# include "ft_printf.h"
# include <ctype.h>

int g_a;
int g_i;
int ret;

int g_negative_precision;
int g_star_zero;
int g_negative_width;

typedef struct	s_data{
	int			zero;
	int			star;
	int			width;
	int			minus;
	int			point;
	int			precision;
	int			g_negative_precision;
	int			g_negative_width;
	int			g_star_zero;
}				t_data;

t_data *g_flags;

void			ft_parse_flags(va_list ap, t_data *g_flags, const char *str);
int				ft_putchar(int c);
int				ft_putstr(char *s);
int				ft_strlen(char *str);
void			treat_width_c(t_data *g_flags, int c);
int				ft_atoi(const char *str);
int				ft_putnum(unsigned long long n, unsigned int base,
					const char *digits);
int				ft_count(unsigned long long n, unsigned int base,
					const char *digits);
void			ft_another_helper_s(t_data *g_flags, int size, char *s, int f);
void			string_minus(t_data *g_flags, int size, char *s, int f);
void			dapped_comparison_s(t_data *g_flags, char *s, int f);
void			ft_print_help_d(t_data *g_flags, void *n, int size);
int				count_numbers(int n);
int				count_numbers_u(unsigned int n);
int				count_numbers_x(unsigned int n);
int				is_conversion(char c);
int				ft_print_p(va_list ap, t_data *g_flags);
int				is_flag(char c);
int				is_digit(int i);
void			print_spaces(t_data *g_flags, int size);
void			ft_print_p_cases(t_data *g_flags, void *n, int size);
void			print_added_spaces(t_data *g_flags, int size);
void			sec_helper(t_data *g_flags, int rem, int *size, int n);
void			print_spaces(t_data *g_flags, int size);
int				ft_print_percent(va_list ap, t_data *g_flags);
void			ft_print_u_minus_prec(t_data *g_flags, int size, int n);
void			ft_print_x_minus_prec(t_data *g_flags, int size,
					unsigned int n);
void			treat_percent_width(t_data *g_flags);
void			flag_setter(const char *str, va_list ap,
					t_data *g_flags, int i);
void			zeroandminus_setters(const char *str, t_data *g_flags, int *i);
void			width_setter(const char *str, va_list ap, int *i, int *ind);
void			helper(t_data *g_flags, int rem, int *size, int n);
int	    		precision_setter(const char *str, va_list ap,
					t_data *g_flags, int *i);
void			space_padder(t_data *g_flags);
void			ft_padded_x(t_data *g_flags, int size, unsigned int n);
int				ft_print_c(va_list ap, t_data *g_flags);
int				ft_print_d(va_list ap, t_data *g_flags);
int				ft_print_u(va_list ap, t_data *g_flags);
int				ft_print_x(va_list ap, t_data *g_flags);
void			treat_precision_nozero_d(t_data *g_flags, int rem,
					int size, int n);
void			treat_precision_alone_d(t_data *g_flags, int rem,
					int size, int n);
int				treat_precision_width_d(t_data *g_flags, int rem,
					int size, int n);
void			ft_special_d(int rem, int *size);
int				treat_precision_zero_d(t_data *g_flags,
					int rem, int size, int n);
void			compare_width_precision(t_data *g_flags, int rem, int ret);
void			printer_zeroes(t_data *g_flags, int rem, int size, int n);
void			treat_minus_width_d(t_data *g_flags, int rem, int size, int n);
void			minus_setter(int rem, int *size);
void			ft_padded_u(t_data *g_flags, int size, unsigned int n);
void			treat_width_d(t_data *g_flags, int rem, int size, int n);
void			treat_width_all_d(t_data *g_flags, int rem, int size, int n);
void			treat_width_zero_d(t_data *g_flags, int rem, int size, int n);
void			ft_print_majx_prec_minus(t_data *g_flags,
					int size, unsigned int n);
int				print_prec_minus_d(t_data *g_flags, int rem,
					int size, int n);
void			treat_precision_no_minus_d(t_data *g_flags, int rem,
					int size, int n);
void			ft_print_majx_minus_prec(t_data *g_flags,
					int size, unsigned int n);
void			ft_prec_nominus_majx(t_data *g_flags, int size, int n);
void			ft_xtra_help(int size, int n);
void			ft_x_help(int size, int n);
void			treat_precision_zero_negative_d(t_data *g_flags, int *size);
int				treat_precision_zero_positive(t_data *g_flags, int size, int n);
int				ft_print_maj_x(va_list ap, t_data *g_flags);
void			treat_precision_d(t_data *g_flags, int rem, int size, int n);
void			ft_padded_majx(t_data *g_flags, int size, unsigned int n);
int				ft_prec_majxtracases_x(t_data *g_flags, int size, int n);
void			ft_dapped_majx(t_data *g_flags, int size, unsigned int n);
void			ft_width_padded_majx(t_data *g_flags, int size, unsigned int n);
void			ft_prec_padded_majx(t_data *g_flags, int size, unsigned int n);
void			ft_helper_majx(t_data *g_flags, int n);
void			treat_precision_positive(t_data *g_flags, int size, int n);
int				treat_precision_zero_positive_d(t_data *g_flags,
					int *size, int n);
void			treat_nullprecision_width_size(t_data *g_flags,
					int rem, int size);
void			treat_precision_width_remaining_d(t_data *g_flags,
					int rem, int size);
int				treat_preczero_width_d(t_data *g_flags, int rem,
					int size, int n);
void			treat_precisionsize_width(t_data *g_flags, int rem, int size);
void			ft_dapped_u(t_data *g_flags, int size, unsigned int n);
int				print_precision_minus(t_data *g_flags, int rem,
					int size, int n);
void			ft_printf_u_point_minus(t_data *g_flags, int size,
					unsigned int n);
int				ft_printf_u_prec_nominus(t_data *g_flags, int size,
					unsigned int n);
void			ft_printf_u_prec_widthnm(t_data *g_flags, int size,
					unsigned int n);
void			ft_printf_u_width_prec(t_data *g_flags, int size,
					unsigned int n);
void			ft_printf_u_moins_prec(t_data *g_flags, int size,
					unsigned int n);
void			ft_width_padded_x(t_data *g_flags, int size, unsigned int n);
int				ft_prec_xtracases_x(t_data *g_flags, int size, int n);
void			ft_prec_padded_x(t_data *g_flags, int size, unsigned int n);
void    		ft_x_special(t_data *g_flags);
void			ft_dapped_x(t_data *g_flags, int size, unsigned int n);
void			ft_printf_aux(const char *fmt, va_list ap, t_data *g_flags);
void			ft_prec_nominus_x(t_data *g_flags, int size, int n);
int				ft_printf(const char *fmt, ...);
void			ft_helper_x(t_data *g_flags, int n);
void			ft_print_s_prec(t_data *g_flags, char *s, int f);
void			count_right_s_size(int size, char *s, int f);
int				precision_holder_d(t_data *g_flags, int rem, int size, int n);
void			padded_s(t_data *g_flags, int size, char *s);
void			dapped_s(t_data *g_flags, int size, char *s);
void			padded_comparison_s(t_data *g_flags, char *s, int f);
int				ft_print_string(va_list ap, t_data *g_flags);
void			ft_helperflagconcarne(int size, char *s, int f);
void			ft_flagsnominus_point(int size, char *s, int f, int set_null);

#endif
