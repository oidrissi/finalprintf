/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:32:14 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 15:01:33 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	ft_inits(t_data *g_flags)
{
	g_flags->zero = 0;
	g_flags->star = 0;
	g_flags->width = 0;
	g_flags->minus = 0;
	g_flags->point = 0;
	g_flags->precision = 0;
	g_negative_precision = 0;
	g_negative_width = 0;
	g_star_zero = 0;
	return (*g_flags);
}

void			ft_parse_flags(va_list ap, t_data *g_flags, const char *str)
{
	int i;

	i = 0;
	flag_setter(str, ap, g_flags, i);
}

typedef int	(*t_ft_print_dispatch_f)(va_list ap, t_data *g_flags);

static t_ft_print_dispatch_f const g_ft_print_dispatch_f[256] =
{
	['c'] = ft_print_c,
	['d'] = ft_print_d,
	['i'] = ft_print_d,
	['%'] = ft_print_percent,
	['p'] = ft_print_p,
	['u'] = ft_print_u,
	['x'] = ft_print_x,
	['X'] = ft_print_maj_x,
	['s'] = ft_print_string,
};

void			ft_printf_aux(const char *fmt, va_list ap, t_data *g_flags)
{
	int i;
	int faulty;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%' && fmt[i + 1] == '%')
			ft_putchar(fmt[i++]);
		else if (fmt[i] == '%')
		{
			if (fmt[i + 1] == '\0')
				break ;
			i++;
			ft_parse_flags(ap, g_flags, fmt + i);
			while (is_flag(fmt[i]))
				i++;
			if (g_flags->width && !is_conversion(fmt[i]))
				break ;
			faulty = g_ft_print_dispatch_f[(unsigned int)fmt[i]](ap, g_flags);
		}
		else
			ft_putchar(fmt[i]);
		ft_inits(g_flags);
		i++;
	}
}

int				ft_printf(const char *fmt, ...)
{
	va_list ap;

	g_a = 0;
	g_flags = malloc(sizeof(t_data));
	ft_inits(g_flags);
	va_start(ap, fmt);
	ft_printf_aux(fmt, ap, g_flags);
	va_end(ap);
	free(g_flags);
	return (g_a);
}
