/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:09:10 by mromao-s          #+#    #+#             */
/*   Updated: 2025/11/24 21:35:11 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	if (!s[0])
		return (0);
	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
	return (i);
}

int	ft_putnmbr(int i)
{
	int		cnt;
	char	c;

	cnt = 0;
	if (i == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (i < 0)
	{
		ft_putstr("-");
		i *= -1;
		cnt++;
	}
	if (i > 9)
		cnt += ft_putnmbr(i / 10);
	c = i % 10 + 48;
	write(1, &c, 1);
	cnt++;
	return (cnt);
}

int	ft_ptr(unsigned long long nb, char *base, int b_size, int exec)
{
	int		cnt;

	cnt = 0;
	if (!nb && exec == 0)
		return (write(1, "(nil)", 5));
	if (exec == 0)
	{
		ft_putstr("0x");
		cnt += 2;
	}
	if (nb / b_size > 0)
		cnt += ft_ptr(nb / b_size, base, b_size, 1);
	write(1, &base[nb % b_size], 1);
	cnt++;
	return (cnt);
}

int	ft_putargs(va_list args, char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (type == '%')
		return (write(1, "%", 1));
	if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (type == 'i' || type == 'd')
		return (ft_putnmbr(va_arg(args, int)));
	if (type == 'p')
		return (ft_ptr(va_arg(args, unsigned long), "0123456789abcdef", 16, 0));
	if (type == 'x')
		return (ft_ptr(va_arg(args, unsigned int), "0123456789abcdef", 16, 1));
	if (type == 'X')
		return (ft_ptr(va_arg(args, unsigned int), "0123456789ABCDEF", 16, 1));
	if (type == 'u')
		return (ft_ptr(va_arg(args, unsigned int), "0123456789ABCDEF", 10, 1));
	return (0);
}
