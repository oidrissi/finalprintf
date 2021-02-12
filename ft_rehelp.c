/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rehelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:34:19 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:54:00 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dapped_u(t_data *g_flags, int size, unsigned int n)
{
	print_spaces(g_flags, size);
	ft_putnum(n, 10, "0123456789");
}

void	ft_padded_x(t_data *g_flags, int size, unsigned int n)
{
	ft_putnum(n, 16, "0123456789abcdef");
	print_spaces(g_flags, size);
}

void	ft_dapped_x(t_data *g_flags, int size, unsigned int n)
{
	print_spaces(g_flags, size);
	ft_putnum(n, 16, "0123456789abcdef");
}

void	ft_width_padded_x(t_data *g_flags, int size, unsigned int n)
{
	while (g_flags->width-- > size)
		ft_putchar('0');
	ft_putnum(n, 16, "0123456789abcdef");
}

void	ft_prec_padded_x(t_data *g_flags, int size, unsigned int n)
{
	while (g_flags->precision-- > size)
		ft_putchar('0');
	ft_putnum(n, 16, "0123456789abcdef");
}
