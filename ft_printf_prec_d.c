/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prec_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:59:53 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 15:14:08 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	treat_precisionsize_width(t_data *g_flags, int rem, int size)
{
	if (rem == 1)
	{
		while (g_flags->width-- > g_flags->precision + 1)
			ft_putchar(' ');
		minus_setter(rem, &size);
		while (g_flags->precision-- > size)
			ft_putchar('0');
	}
	else
		print_spaces(g_flags, size);
}

void	treat_precision_width_remaining_d(t_data *g_flags, int rem, int size)
{
	if (g_flags->precision < size)
	{
		print_spaces(g_flags, size);
		minus_setter(rem, &size);
	}
	else
	{
		while (g_flags->width-- > g_flags->precision)
			ft_putchar(' ');
	}
}

int		treat_preczero_width_d(t_data *g_flags, int rem, int size, int n)
{
	if (n == 0)
	{
		while (g_flags->width-- > 0)
			ft_putchar(' ');
		return (0);
	}
	print_spaces(g_flags, size);
	minus_setter(rem, &size);
	return (1);
}

int		precision_holder_d(t_data *g_flags, int rem, int size, int n)
{
	if (g_flags->precision == 0)
	{
		if (n == 0)
		{
			while (g_flags->width-- > 0)
				ft_putchar(' ');
			return (0);
		}
		print_spaces(g_flags, size);
		minus_setter(rem, &size);
	}
	else if (g_flags->precision > size)
		treat_nullprecision_width_size(g_flags, rem, size);
	else if (g_flags->precision == size)
		treat_precisionsize_width(g_flags, rem, size);
	else
		treat_precision_width_remaining_d(g_flags, rem, size);
	return (1);
}

int		treat_precision_width_d(t_data *g_flags, int rem, int size, int n)
{
	if (g_flags->width > g_flags->precision)
	{
		if (g_flags->width > size)
		{
			if (!precision_holder_d(g_flags, rem, size, n))
				return (0);
		}
		else if (g_flags->width == size &&
			g_flags->precision < size && rem == 1)
			ft_putchar('-');
		else if (!g_flags->precision && g_flags->width && n == 0)
		{
			ft_putchar(' ');
			return (0);
		}
		else if (g_flags->width < size && g_flags->precision == 0)
			minus_setter(rem, &size);
	}
	else
		ft_special_d(rem, &size);
	ft_putnum((int)n, 10, "0123456789");
	return (1);
}
