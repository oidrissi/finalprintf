/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:07:29 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/09 12:16:22 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_numbers(int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		length++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length++);
}

int	count_numbers_u(unsigned int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length++);
}

int	count_numbers_x(unsigned int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		length++;
	}
	return (length++);
}

int	ft_count(unsigned long long n,
	unsigned int base, const char *digits)
{
	int res;

	res = 1;
	if (n >= base)
		res += ft_count(n / base, base, digits);
	g_i++;
	return (g_i);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
