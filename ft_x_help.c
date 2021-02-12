/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:48:43 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 15:20:23 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_helper_x(t_data *g_flags, int n)
{
	if (!g_flags->minus)
	{
		ft_putchar(' ');
		ft_putnum(n, 16, "0123456789abcdef");
	}
	else
	{
		ft_putnum(n, 16, "0123456789abcdef");
		ft_putchar(' ');
	}
}

void	ft_x_special(t_data *g_flags)
{
	ft_putchar(' ');
	while (g_flags->precision-- > 2)
		ft_putchar('0');
	ft_putchar(' ');
}

void	ft_special_d(int rem, int *size)
{
	minus_setter(rem, size);
	while (g_flags->precision-- > *size)
		ft_putchar('0');
}

void	ft_xtra_help(int size, int n)
{
	while (g_flags->width-- > g_flags->precision)
		ft_putchar(' ');
	ft_prec_padded_majx(g_flags, size, n);
}

void	ft_x_help(int size, int n)
{
	while (g_flags->width-- > g_flags->precision)
		ft_putchar(' ');
	ft_prec_padded_x(g_flags, size, n);
}
