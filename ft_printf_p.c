/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:03:38 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 15:02:14 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_help_d(t_data *g_flags, void *n, int size)
{
	if (n == NULL)
	{
		if (g_flags->width == 2)
			ft_putstr("0x");
		else
		{
			while (g_flags->width-- > size + 1)
			{
				ft_putchar(' ');
				g_flags->width--;
			}
			ft_putstr(" 0x");
		}
	}
}

void	ft_print_p_cases(t_data *g_flags, void *n, int size)
{
	if (g_flags->minus)
	{
		ft_putstr("0x");
		ft_putnum((unsigned long long)n, 16,
			"0123456789abcdefghijklmnopqrstuvwxyz");
		while (g_flags->width > size + 2)
		{
			ft_putchar(' ');
			g_flags->width--;
		}
	}
	else if (g_flags->point)
		ft_print_help_d(g_flags, n, size);
	else
	{
		while (g_flags->width > size + 2)
		{
			ft_putchar(' ');
			g_flags->width--;
		}
		ft_putstr("0x");
		ft_putnum((unsigned long long)n, 16,
			"0123456789abcdefghijklmnopqrstuvwxyz");
	}
}

int		ft_print_p(va_list ap, t_data *g_flags)
{
	void	*n;
	int		size;
	int		j;

	g_i = 0;
	n = va_arg(ap, void*);
	j = ((unsigned int)n);
	size = ft_count((unsigned long long)n, 16,
		"0123456789abcdefghijklmnopqrstuvwxyz");
	if (g_flags->width)
		ft_print_p_cases(g_flags, n, size);
	else if (n == NULL && g_flags->point)
		ft_putstr("0x");
	else
	{
		ft_putstr("0x");
		ft_putnum((unsigned long long)n, 16,
			"0123456789abcdefghijklmnopqrstuvwxyz");
	}
	return (1);
}
