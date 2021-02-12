/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:00:49 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:54:28 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s_prec(t_data *g_flags, char *s, int f)
{
	while (g_flags->precision-- > 0)
		ft_putchar(s[f++]);
}

void	count_right_s_size(int size, char *s, int f)
{
	while (size-- > 0)
		ft_putchar(s[f++]);
}

void	padded_s(t_data *g_flags, int size, char *s)
{
	print_spaces(g_flags, size);
	ft_putstr(s);
}

void	dapped_s(t_data *g_flags, int size, char *s)
{
	ft_putstr(s);
	print_spaces(g_flags, size);
}

void	padded_comparison_s(t_data *g_flags, char *s, int f)
{
	while (g_flags->width-- > g_flags->precision)
		ft_putchar(' ');
	ft_print_s_prec(g_flags, s, f);
}
