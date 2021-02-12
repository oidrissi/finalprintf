/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:01:03 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:55:46 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zeroandminus_setters(const char *str, t_data *g_flags, int *i)
{
	if (str[*i] == '-')
	{
		g_flags->minus = 1;
		(*i)++;
	}
	else if (str[*i] == '0')
	{
		g_flags->zero = 1;
		if (str[*i + 1] == '*')
			g_star_zero = 1;
		(*i)++;
	}
}

void	width_setter(const char *str, va_list ap, int *i, int *ind)
{
	if (is_digit(str[*i]))
	{
		if (*ind == 0)
		{
			g_flags->width = ft_atoi(str + *i);
			*ind = 1;
		}
		if (*ind == 1)
			*i += count_numbers(g_flags->width);
	}
	else if (str[*i] == '*')
	{
		g_flags->width = va_arg(ap, int);
		(*i)++;
		if (g_flags->width < 0)
		{
			g_negative_width = 1;
			g_flags->width *= -1;
			g_flags->minus = 1;
		}
	}
}

int		precision_setter(const char *str, va_list ap, t_data *g_flags, int *i)
{
	if (str[*i] == '.')
	{
		g_flags->point = 1;
		if (is_digit(str[*i + 1]))
		{
			g_flags->precision = atoi(str + *i + 1);
			*i += count_numbers(g_flags->precision);
			return (0);
		}
		else if (str[*i + 1] == '*')
		{
			g_flags->star += 1;
			g_flags->precision = va_arg(ap, int);
			if (g_flags->precision < 0)
			{
				g_negative_precision = 1;
				g_flags->precision = 0;
			}
			if (str[*i + 1] != 0)
				*i += count_numbers(g_flags->precision);
		}
	}
	return (1);
}

void	flag_setter(const char *str, va_list ap, t_data *g_flags, int i)
{
	int ind;

	ind = 0;
	while (str[i])
	{
		zeroandminus_setters(str, g_flags, &i);
		width_setter(str, ap, &i, &ind);
		if (!precision_setter(str, ap, g_flags, &i))
			break ;
		if (is_conversion(str[i]))
			break ;
		i++;
	}
}
