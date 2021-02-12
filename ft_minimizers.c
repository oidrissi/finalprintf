/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimizers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:51:45 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:49:17 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_setter(int rem, int *size)
{
	if (rem == 1)
	{
		ft_putchar('-');
		*size -= 1;
	}
}

void	printer_zeroes(t_data *g_flags, int rem, int size, int n)
{
	minus_setter(rem, &size);
	while (g_flags->precision-- > size)
		ft_putchar('0');
	ft_putnum((int)n, 10, "0123456789");
}

void	compare_width_precision(t_data *g_flags, int rem, int ret)
{
	if (rem == 1)
	{
		while (g_flags->width-- > ret + 1)
			ft_putchar(' ');
	}
	else
	{
		while (g_flags->width-- > ret)
			ft_putchar(' ');
	}
}

void	print_spaces(t_data *g_flags, int size)
{
	while (g_flags->width-- > size)
		ft_putchar(' ');
}

void	print_added_spaces(t_data *g_flags, int size)
{
	while (g_flags->width-- > size + 1)
		ft_putchar(' ');
}
