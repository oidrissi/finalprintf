/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uhelp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:31:48 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:52:25 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u_minus_prec(t_data *g_flags, int size, int n)
{
	ret = g_flags->precision;
	while (g_flags->precision-- > size)
		ft_putchar('0');
	ft_putnum(n, 10, "0123456789");
	while (g_flags->width-- > ret)
		ft_putchar(' ');
}

void	ft_printf_u_point_minus(t_data *g_flags, int size, unsigned int n)
{
	if (n == 0 && g_flags->precision == 0 && g_flags->width)
	{
		while (g_flags->width-- > 0)
			ft_putchar(' ');
	}
	else if (g_flags->width > g_flags->precision && g_flags->precision < size)
	{
		ft_putnum(n, 10, "0123456789");
		while (g_flags->width-- > size)
			ft_putchar(' ');
	}
	else if (g_flags->precision > g_flags->width && g_flags->precision > size)
	{
		while (g_flags->precision-- > size)
			ft_putchar('0');
		ft_putnum(n, 10, "0123456789");
	}
	else if (g_flags->width > g_flags->precision && g_flags->precision == size)
		ft_padded_u(g_flags, size, n);
	else
		ft_putnum(n, 10, "0123456789");
}
