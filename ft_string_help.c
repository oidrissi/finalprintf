/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:02:17 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:54:22 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dapped_comparison_s(t_data *g_flags, char *s, int f)
{
	ft_print_s_prec(g_flags, s, f);
	while (g_flags->width-- > g_flags->precision)
		ft_putchar(' ');
}

void	ft_helperflagconcarne(int size, char *s, int f)
{
	if (g_flags->precision < size)
		ft_print_s_prec(g_flags, s, f);
	else
		count_right_s_size(size, s, f);
}
