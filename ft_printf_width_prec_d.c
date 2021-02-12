/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width_prec_d.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:01:32 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:53:25 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	treat_precision_zero_negative_d(t_data *g_flags, int *size)
{
	if (g_flags->precision < *size)
	{
		if (g_negative_precision != 1)
		{
			while (g_flags->width-- > *size)
				ft_putchar(' ');
			ft_putchar('-');
		}
		else
		{
			ft_putchar('-');
			while (g_flags->width-- > *size)
				ft_putchar('0');
		}
	}
	else
	{
		while (g_flags->width-- > g_flags->precision + 1)
			ft_putchar(' ');
		ft_putchar('-');
	}
	(*size)--;
}

int		treat_precision_zero_positive_d(t_data *g_flags, int *size, int n)
{
	if (g_negative_precision != 1)
	{
		if (g_flags->precision == 0 && n == 0)
		{
			while (g_flags->width-- > 1)
				ft_putchar(' ');
			return (0);
		}
		else
		{
			while (g_flags->width-- > *size)
				ft_putchar(' ');
		}
	}
	else
	{
		while (g_flags->width-- > *size)
			ft_putchar('0');
	}
	(*size)--;
	return (0);
}

void	treat_precision_positive(t_data *g_flags, int size, int n)
{
	if (g_flags->precision < size)
	{
		if (g_negative_precision != 1)
			treat_precision_zero_positive_d(g_flags, &size, n);
		else
		{
			while (g_flags->width-- > size)
				ft_putchar('0');
		}
	}
	else if ((g_flags->precision > size) || (g_flags->precision == size &&
	g_flags->width > g_flags->precision) || (g_flags->precision == 1 && n == 0))
	{
		while (g_flags->width-- > g_flags->precision)
			ft_putchar(' ');
	}
	else
	{
		while (g_flags->width-- > g_flags->precision + 1)
			ft_putchar(' ');
	}
}

int		treat_precision_zero_d(t_data *g_flags, int rem, int size, int n)
{
	if (rem == 1)
		treat_precision_zero_negative_d(g_flags, &size);
	else
		treat_precision_positive(g_flags, size, n);
	while (g_flags->precision-- > size)
		ft_putchar('0');
	if (n == 0 && g_flags->precision != 0)
	{
		ft_putchar(' ');
		return (0);
	}
	ft_putnum((int)n, 10, "0123456789");
	return (1);
}

int		print_precision_minus(t_data *g_flags, int rem, int size, int n)
{
	ret = g_flags->precision;
	if ((g_flags->precision > g_flags->width) ||
	(g_flags->width == g_flags->precision && rem == 1))
		printer_zeroes(g_flags, rem, size, n);
	else if (g_flags->width == g_flags->precision && n == 0)
	{
		while (g_flags->precision-- > 0)
			ft_putchar('0');
	}
	else if (!g_flags->precision && n == 0)
	{
		while (g_flags->width-- > 0)
			ft_putchar(' ');
	}
	else if (g_flags->precision == g_flags->width)
		helper(g_flags, rem, &size, n);
	else
	{
		sec_helper(g_flags, rem, &size, n);
		if (ret > size)
			compare_width_precision(g_flags, rem, ret);
		else
			print_prec_minus_d(g_flags, rem, size, n);
	}
	return (1);
}
