/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:36:02 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 15:20:45 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_x_minus_prec(t_data *g_flags, int size, unsigned int n)
{
	ret = g_flags->precision;
	while (g_flags->precision-- > size)
		ft_putchar('0');
	ft_putnum(n, 16, "0123456789abcdef");
	while (g_flags->width-- > ret)
		ft_putchar(' ');
}

void	ft_print_x_prec_minus(t_data *g_flags, int size, unsigned int n)
{
	if (g_flags->width > g_flags->precision && g_flags->precision > size)
		ft_print_x_minus_prec(g_flags, size, n);
	else if (n == 0 && g_flags->precision == 0 && g_flags->width)
		space_padder(g_flags);
	else if (g_flags->width > g_flags->precision && g_flags->precision < size)
		ft_padded_x(g_flags, size, n);
	else if (g_flags->precision > g_flags->width && g_flags->precision > size
			&& size > g_flags->width && n != 0)
		ft_prec_padded_x(g_flags, size, n);
	else if (g_flags->precision > g_flags->width && g_flags->precision > size)
		ft_prec_padded_x(g_flags, size, n);
	else if (g_flags->precision > size && n == 0
			&& g_flags->precision != g_flags->width)
		ft_x_special(g_flags);
	else if (g_flags->precision == g_flags->width && n == 0)
	{
		while (g_flags->precision-- > 0)
			ft_putchar('0');
	}
	else if (g_flags->width > g_flags->precision && g_flags->precision == size)
		ft_padded_x(g_flags, size, n);
	else if (g_flags->precision == g_flags->width && g_flags->precision > size)
		ft_prec_padded_x(g_flags, size, n);
	else
		ft_putnum(n, 16, "0123456789abcdef");
}

void	ft_prec_nominus_x(t_data *g_flags, int size, int n)
{
	if (n == 0)
	{
		while (g_flags->precision--)
			ft_putchar('0');
	}
	else if (n != 0 && g_flags->precision > size &&
		size > g_flags->width && g_flags->width != 0)
		ft_prec_padded_x(g_flags, size, n);
	else
		ft_prec_padded_x(g_flags, size, n);
}

int		ft_prec_xtracases_x(t_data *g_flags, int size, int n)
{
	if (g_flags->precision > g_flags->width)
		ft_prec_nominus_x(g_flags, size, n);
	else if (n == 0 && g_flags->precision == 0 && !g_flags->width)
		return (0);
	else if (n == 0 && g_flags->precision == 0 && g_flags->width)
		space_padder(g_flags);
	else if (g_flags->precision == g_flags->width && g_flags->precision > size)
		ft_prec_padded_x(g_flags, size, n);
	else
	{
		if (g_flags->width > g_flags->precision && g_flags->precision > size)
			ft_x_help(size, n);
		else if (g_flags->width > g_flags->precision
		&& g_flags->precision < size)
			ft_dapped_x(g_flags, size, n);
		else if (g_flags->zero && g_flags->width > g_flags->precision
			&& g_flags->width > size)
			ft_dapped_x(g_flags, size, n);
		else
			ft_putnum(n, 16, "0123456789abcdef");
	}
	return (1);
}

int		ft_print_x(va_list ap, t_data *g_flags)
{
	unsigned int	n;
	int				size;

	n = va_arg(ap, unsigned int);
	size = count_numbers_x(n);
	if (g_flags->point && g_flags->minus)
		ft_print_x_prec_minus(g_flags, size, n);
	else if (g_flags->point && !g_flags->minus)
		ft_prec_xtracases_x(g_flags, size, n);
	else if (g_flags->width > size)
	{
		if (g_flags->minus && !g_flags->point)
			ft_padded_x(g_flags, size, n);
		else if (g_flags->zero && !g_flags->minus)
			ft_width_padded_x(g_flags, size, n);
		else
			ft_dapped_x(g_flags, size, n);
	}
	else if (g_flags->width == size)
		ft_helper_x(g_flags, n);
	else
		ft_putnum(n, 16, "0123456789abcdef");
	return (1);
}
