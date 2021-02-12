/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:49:47 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:49:32 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(va_list ap, t_data *g_flags)
{
	int c;
	int	size;

	c = va_arg(ap, int);
	size = 1;
	if (g_flags->width)
		treat_width_c(g_flags, c);
	else
		ft_putchar(c);
	return (1);
}
