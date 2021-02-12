/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:12:01 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:51:43 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagsnominus_point(int size, char *s, int f, int set_null)
{
	if (g_flags->precision && g_flags->precision < size && !g_flags->width)
		ft_print_s_prec(g_flags, s, f);
	else if (g_flags->precision && g_flags->precision > size
		&& g_flags->width > size)
		padded_s(g_flags, size, s);
	else if (g_flags->precision == 0 && g_flags->width == 0)
		ft_print_s_prec(g_flags, s, f);
	else if (g_flags->width > g_flags->precision && g_flags->width < size)
		padded_comparison_s(g_flags, s, f);
	else if (g_flags->width > g_flags->precision && g_flags->width > size)
		padded_comparison_s(g_flags, s, f);
	else if (g_flags->width == g_flags->precision && g_flags->precision < size)
		ft_print_s_prec(g_flags, s, f);
	else if (g_flags->precision == 0 && g_flags->width == size)
	{
		while (size-- > 0)
			ft_putchar(' ');
	}
	else if (g_flags->precision > g_flags->width
		&& g_flags->width > 0 && set_null == 1)
		ft_helperflagconcarne(size, s, f);
	else if (g_flags->width == size && g_flags->precision < size)
		padded_comparison_s(g_flags, s, f);
	else
		ft_putstr(s);
}

void	ft_another_helper_s(t_data *g_flags, int size, char *s, int f)
{
	int		s_size;

	s_size = size;
	if (g_flags->width && !g_flags->point)
		dapped_s(g_flags, size, s);
	else if (g_flags->point && g_flags->width > g_flags->precision)
	{
		if (g_negative_precision == 0)
		{
			while (g_flags->precision-- > 0)
			{
				if (s[f] == '\0')
					break ;
				ft_putchar(s[f++]);
				g_flags->width--;
			}
			space_padder(g_flags);
		}
		else
		{
			count_right_s_size(size, s, f);
			while (g_flags->width-- > s_size)
				ft_putchar(' ');
		}
	}
}

void	string_minus(t_data *g_flags, int size, char *s, int f)
{
	if (g_flags->width && !g_flags->point)
		dapped_s(g_flags, size, s);
	else if (g_flags->point && g_flags->width > g_flags->precision)
		ft_another_helper_s(g_flags, size, s, f);
	else if (g_flags->point && g_flags->width < g_flags->precision
		&& g_flags->precision > size)
		dapped_s(g_flags, size, s);
	else if (g_flags->width == g_flags->precision && g_flags->precision > size)
		dapped_s(g_flags, size, s);
	else if (g_flags->width == g_flags->precision && g_flags->precision < size)
	{
		while (g_flags->precision-- > 0)
		{
			ft_putchar(s[f++]);
			g_flags->width--;
		}
		print_spaces(g_flags, size);
	}
	else if (g_flags->width > g_flags->precision && g_flags->width > size)
	{
		ft_print_s_prec(g_flags, s, f);
		dapped_comparison_s(g_flags, s, f);
	}
	else
		ft_putstr(s);
}

int		ft_print_string(va_list ap, t_data *g_flags)
{
	char	*s;
	int		f;
	int		size;
	int		set_null;

	set_null = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
	{
		s = "(null)";
		set_null = 1;
	}
	size = ft_strlen(s);
	f = 0;
	if (!g_flags->minus && !g_flags->point && !g_flags->width)
		ft_putstr(s);
	else if (g_flags->point && !g_flags->minus)
		ft_flagsnominus_point(size, s, f, set_null);
	else if (g_flags->minus)
		string_minus(g_flags, size, s, f);
	else if (g_flags->width && !g_flags->minus && !g_flags->point)
		padded_s(g_flags, size, s);
	if (!g_flags->width && g_negative_precision == 1)
		count_right_s_size(size, s, f);
	return (1);
}
