/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:49:33 by mromao-s          #+#    #+#             */
/*   Updated: 2025/12/10 20:52:50 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;

	va_start(args, str);
	print_len = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			print_len += ft_putargs(args, *str);
		}
		else
			print_len += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (print_len);
}

/* int	main(void) {
	// ft_printf("%asda%sPUTA%dasdasda\n",
// "\n\n\n\n\n\n\n", "asd", "asd", "asd");
	int	i = ft_printf(" %i %d\n", 120, 0);
	int	j = printf(" %i %d\n", 120, 0);
	// int	j = printf("%i\n%c\n%s\n", 123, "123", "c\n\n");
	// int	nb = ft_putnmbr(-56564);
	printf("%i\n", i - j);
	return (0);
} */
