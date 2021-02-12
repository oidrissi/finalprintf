/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:09:50 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:52:05 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_u_moins_prec(t_data *g_flags, int size, unsigned int n)
{
	if (g_flags->width > g_flags->precision && g_flags->precision > size)
		ft_print_u_minus_prec(g_flags, size, n);
	else
		ft_printf_u_point_minus(g_flags, size, n);
	if (g_flags->precision == g_flags->width && n == 0)
	{
		while (g_flags->precision-- > 1)
			ft_putchar('0');
	}
}

void	ft_printf_u_width_prec(t_data *g_flags, int size, unsigned int n)
{
	if (g_flags->minus && !g_flags->point)
		ft_padded_u(g_flags, size, n);
	else if (g_flags->zero && !g_flags->minus)
	{
		while (g_flags->width-- > size)
		{
			ft_putchar('0');
		}
		ft_putnum(n, 10, "0123456789");
	}
	else
		ft_dapped_u(g_flags, size, n);
}

int		ft_printf_u_prec_nominus(t_data *g_flags, int size, unsigned int n)
{
	if (g_flags->precision > g_flags->width)
	{
		while (g_flags->precision-- > size)
			ft_putchar('0');
		ft_putnum(n, 10, "0123456789");
	}
	else if (n == 0 && g_flags->precision == 0 && !g_flags->width)
		return (0);
	else if (n == 0 && g_flags->precision == 0 && g_flags->width)
		space_padder(g_flags);
	else if (g_flags->width > g_flags->precision && g_flags->precision == size)
		ft_dapped_u(g_flags, size, n);
	else if (g_flags->precision == g_flags->width && n == 0)
	{
		while (g_flags->precision-- > 0)
			ft_putchar('0');
	}
	else
		ft_printf_u_prec_widthnm(g_flags, size, n);
	return (1);
}

void	ft_printf_u_prec_widthnm(t_data *g_flags, int size, unsigned int n)
{
	if (g_flags->width > g_flags->precision && g_flags->precision > size)
	{
		while (g_flags->width-- > g_flags->precision)
			ft_putchar(' ');
		while (g_flags->precision-- > size)
			ft_putchar('0');
		ft_putnum(n, 10, "0123456789");
	}
	else if (g_flags->width > g_flags->precision && g_flags->precision < size)
		ft_dapped_u(g_flags, size, n);
	else if (g_flags->zero && g_flags->width == g_flags->precision && n == 0)
	{
		while (g_flags->width-- > 0)
			ft_putchar('0');
	}
	else
		ft_putnum(n, 10, "0123456789");
}

int		ft_print_u(va_list ap, t_data *g_flags)
{
	unsigned int	n;
	int				size;

	n = va_arg(ap, unsigned int);
	size = count_numbers_u(n);
	if (g_flags->point && g_flags->minus)
		ft_printf_u_moins_prec(g_flags, size, n);
	else if (g_flags->point && !g_flags->minus)
		ft_printf_u_prec_nominus(g_flags, size, n);
	else if (g_flags->width > size)
		ft_printf_u_width_prec(g_flags, size, n);
	else
		ft_putnum(n, 10, "0123456789");
	return (1);
}
