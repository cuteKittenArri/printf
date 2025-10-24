/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmuller <stmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:33:23 by stmuller          #+#    #+#             */
/*   Updated: 2025/10/24 21:07:29 by stmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ptr_digits(unsigned long long n);
static void		put_ptr(unsigned long long addr);

int	ft_put_ptr(void *addr)
{
	if (addr == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	put_ptr((unsigned long long)addr);
	return (ptr_digits((unsigned long long)addr) + 2);
}

static size_t	ptr_digits(unsigned long long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

static void	put_ptr(unsigned long long addr)
{
	static char	digits[] = "0123456789abcdef";

	if (addr >= 16)
		put_ptr(addr / 16);
	write(1, &digits[addr % 16], 1);
}
