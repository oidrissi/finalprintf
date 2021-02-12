/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:53:20 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:52:56 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	treat_width_d(t_data *g_flags, int rem, int size, int n)
{
	if (g_flags->width > size)
	{
		print_spaces(g_flags, size);
		minus_setter(rem, &size);
		if (n == 0)
			ft_putchar('0');
		else
			ft_putnum(n, 10, "0123456789");
	}
	else
	{
		if (rem == 1)
			ft_putchar('-');
		ft_putnum(n, 10, "0123456789");
	}
}

void	treat_width_zero_d(t_data *g_flags, int rem, int size, int n)
{
	if (g_flags->width > size)
	{
		if (rem == 1)
			ft_putchar('-');
		if (g_flags->zero)
		{
			while (g_flags->width-- > size)
				ft_putchar('0');
		}
		ft_putnum(n, 10, "0123456789");
		print_spaces(g_flags, size);
	}
	else
	{
		if (rem == 1)
			ft_putchar('-');
		ft_putnum(n, 10, "0123456789");
	}
}

void	treat_precision_alone_d(t_data *g_flags, int rem, int size, int n)
{
	if (!g_flags->minus && !g_flags->zero && !g_flags->width)
	{
		if (g_flags->precision > size)
		{
			minus_setter(rem, &size);
			while (g_flags->precision-- > size)
				ft_putchar('0');
		}
		else if (g_flags->precision == size && rem == 1)
			ft_putstr("-0");
		else
			minus_setter(rem, &size);
		ft_putnum((int)n, 10, "0123456789");
	}
}

void	treat_minus_width_d(t_data *g_flags, int rem, int size, int n)
{
	if (!g_flags->zero)
	{
		if (g_flags->width > size)
		{
			if (rem == 1)
				ft_putchar('-');
			ft_putnum(n, 10, "0123456789");
			print_spaces(g_flags, size);
		}
		else
		{
			minus_setter(rem, &size);
			ft_putnum((int)n, 10, "0123456789");
		}
	}
	else
	{
		if (rem == 1)
			ft_putchar('-');
		ft_putnum((int)n, 10, "0123456789");
		if (g_negative_width == 1)
			print_spaces(g_flags, size);
	}
}

void	treat_nullprecision_width_size(t_data *g_flags, int rem, int size)
{
	if (rem == 1)
	{
		while (g_flags->width-- > g_flags->precision + 1)
			ft_putchar(' ');
		minus_setter(rem, &size);
	}
	else
	{
		while (g_flags->width-- > g_flags->precision)
			ft_putchar(' ');
	}
	while (g_flags->precision-- > size)
		ft_putchar('0');
}
