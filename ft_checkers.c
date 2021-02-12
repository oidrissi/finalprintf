/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:32:23 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:48:18 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conversion(char c)
{
	return ((c == 's' || c == 'c' || c == 'x' || c == 'X'
		|| c == 'u' || c == 'i' || c == 'd' || c == 'p' || c == '%') ? 1 : 0);
}

int		is_flag(char c)
{
	return (((c == '-' || c == '0' || c == '.' || c == '*'
		|| is_digit(c)) ? 1 : 0));
}

int		is_digit(int c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

int		ft_print_percent(va_list ap, t_data *g_flags)
{
	(void)ap;
	if (g_flags->width)
	{
		treat_percent_width(g_flags);
	}
	else if (g_flags->width == 0)
		ft_putchar('%');
	return (1);
}

void	treat_percent_width(t_data *g_flags)
{
	if (!g_flags->minus && !g_flags->zero)
	{
		while (g_flags->width-- > 1)
			ft_putchar(' ');
		ft_putchar('%');
	}
	else if (g_flags->zero && !g_flags->minus)
	{
		while (g_flags->width-- > 1)
			ft_putchar('0');
		ft_putchar('%');
	}
	else
	{
		ft_putchar('%');
		while (g_flags->width-- > 1)
			ft_putchar(' ');
	}
}
