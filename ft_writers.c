/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:16:50 by oidrissi          #+#    #+#             */
/*   Updated: 2021/02/12 14:54:46 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_a;

int		ft_putchar(int c)
{
	g_a++;
	if (c == '\0')
		return (write(1, &c, 1));
	return (write(1, &c, 1));
}

int		ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int		ft_atoi(const char *str)
{
	int			i;
	int			signe;
	long		z;

	z = 0;
	signe = 1;
	i = 0;
	while (str[i] && (str[i] == '\n' || str[i] == '\r' || str[i] == ' ' ||
				str[i] == '\t' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		z = z * 10 + (str[i] - 48);
		i++;
		if (z < 0 && signe > 0)
			return (-1);
		if (z < 0 && signe < 0)
			return (0);
	}
	return (signe * z);
}

void	treat_width_c(t_data *g_flags, int c)
{
	int size;

	size = 1;
	if (g_flags->minus)
	{
		ft_putchar(c);
		while ((g_flags->width-- - size) > 0)
			ft_putchar(' ');
	}
	else
	{
		while ((g_flags->width-- - size) > 0)
			ft_putchar(' ');
		ft_putchar(c);
	}
}

int		ft_putnum(unsigned long long n,
		unsigned int base, const char *digits)
{
	int res;

	res = 1;
	if ((long)n == -2147483648)
		ft_putstr("214748364");
	else if (n >= base)
		res += ft_putnum(n / base, base, digits);
	ft_putchar(digits[n % base]);
	return (res);
}
