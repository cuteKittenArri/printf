/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmuller <stmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:04:56 by stmuller          #+#    #+#             */
/*   Updated: 2025/10/24 21:04:56 by stmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checker(const char toCheck, va_list args);
int	ft_printf_striter(const char *str, va_list args);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	if (!str)
		return (-1);
	va_start(args, str);
	len = ft_printf_striter(str, args);
	va_end(args);
	return (len);
}

int	ft_printf_striter(const char *str, va_list args)
{
	int	len;
	int	check;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check = checker(*(++str), args);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (write(1, str, 1) == -1)
				return (-1);
			len++;
		}
		str++;
	}
	return (len);
}

static int	checker(const char toCheck, va_list args)
{
	if (toCheck == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (toCheck == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if ((toCheck == 'i') || (toCheck == 'd'))
		return (ft_putnbr(va_arg(args, int)));
	else if (toCheck == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (toCheck == 'x' || toCheck == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), toCheck));
	else if (toCheck == 'p')
		return (ft_put_ptr(va_arg(args, void *)));
	else if (toCheck == '%')
		return (ft_putchar('%'));
	return (-1);
}
