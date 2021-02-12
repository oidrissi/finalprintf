/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_majx_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:04:11 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 15:00:55 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padded_majx(t_data *g_flags, int size, unsigned int n)
{
	ft_putnum(n, 16, "0123456789ABCDEF");
	print_spaces(g_flags, size);
}

void	ft_dapped_majx(t_data *g_flags, int size, unsigned int n)
{
	print_spaces(g_flags, size);
	ft_putnum(n, 16, "0123456789ABCDEF");
}

void	ft_width_padded_majx(t_data *g_flags, int size, unsigned int n)
{
	while (g_flags->width-- > size)
		ft_putchar('0');
	ft_putnum(n, 16, "0123456789ABCDEF");
}

void	ft_prec_padded_majx(t_data *g_flags, int size, unsigned int n)
{
	while (g_flags->precision-- > size)
		ft_putchar('0');
	ft_putnum(n, 16, "0123456789ABCDEF");
}

void	ft_helper_majx(t_data *g_flags, int n)
{
	if (!g_flags->minus)
	{
		ft_putchar(' ');
		ft_putnum(n, 16, "0123456789ABCDEF");
	}
	else
	{
		ft_putnum(n, 16, "0123456789ABCDEF");
		ft_putchar(' ');
	}
}
