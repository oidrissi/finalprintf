/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:03:05 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:50:06 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	treat_precision_nozero_d(t_data *g_flags, int rem, int size, int n)
{
	if (g_flags->precision && !g_flags->width)
		treat_precision_alone_d(g_flags, rem, size, n);
	else if (g_flags->width)
		treat_precision_width_d(g_flags, rem, size, n);
	else if (g_flags->precision == 0 && size > g_flags->precision
			&& n != 0)
	{
		minus_setter(rem, &size);
		ft_putnum((int)n, 10, "0123456789");
	}
}

void	treat_precision_no_minus_d(t_data *g_flags, int rem, int size, int n)
{
	if (!g_flags->zero)
		treat_precision_nozero_d(g_flags, rem, size, n);
	else
		treat_precision_zero_d(g_flags, rem, size, n);
}

void	treat_precision_d(t_data *g_flags, int rem, int size, int n)
{
	if (!g_flags->minus)
		treat_precision_no_minus_d(g_flags, rem, size, n);
	else
		print_precision_minus(g_flags, rem, size, n);
}

void	treat_width_all_d(t_data *g_flags, int rem, int size, int n)
{
	if (!g_flags->minus)
	{
		if (!g_flags->zero)
			treat_width_d(g_flags, rem, size, n);
		else
			treat_width_zero_d(g_flags, rem, size, n);
	}
	else
		treat_minus_width_d(g_flags, rem, size, n);
}

int		ft_print_d(va_list ap, t_data *g_flags)
{
	int n;
	int size;
	int rem;

	ret = g_flags->precision;
	rem = 0;
	n = va_arg(ap, int);
	size = count_numbers(n);
	if (n < 0)
	{
		if (n > -2147483648)
			n *= -1;
		rem = 1;
	}
	if (g_flags->point)
		treat_precision_d(g_flags, rem, size, n);
	else
		treat_width_all_d(g_flags, rem, size, n);
	return (1);
}
