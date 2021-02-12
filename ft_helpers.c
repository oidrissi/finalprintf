/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:02:22 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:46:13 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	helper(t_data *g_flags, int rem, int *size, int n)
{
	minus_setter(rem, size);
	if (*size > g_flags->width)
		ft_putnum((int)n, 10, "0123456789");
}

void	sec_helper(t_data *g_flags, int rem, int *size, int n)
{
	minus_setter(rem, size);
	while (g_flags->precision-- > *size)
		ft_putchar('0');
	ft_putnum((int)n, 10, "0123456789");
}

int		print_prec_minus_d(t_data *g_flags, int rem, int size, int n)
{
	if (rem == 1)
		print_added_spaces(g_flags, size);
	else
	{
		if (n == 0)
		{
			while (g_flags->width-- > 0)
				ft_putchar(' ');
			return (0);
		}
		print_spaces(g_flags, size);
	}
	if (g_flags->precision < size)
		size -= 2;
	else if (g_flags->precision > size)
		ft_putchar('-');
	else
	{
		if (rem == 1)
		{
			size += 1;
			print_spaces(g_flags, size);
		}
	}
	return (1);
}

void	space_padder(t_data *g_flags)
{
	while (g_flags->width--)
		ft_putchar(' ');
}

void	ft_padded_u(t_data *g_flags, int size, unsigned int n)
{
	ft_putnum(n, 10, "0123456789");
	print_spaces(g_flags, size);
}
