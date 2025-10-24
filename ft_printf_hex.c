/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrilein <arrilein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:25:33 by stmuller          #+#    #+#             */
/*   Updated: 2025/10/24 13:17:34 by arrilein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	h_digits(unsigned int n);
static void	put_hexa(unsigned int nbr, char up);

int	ft_put_hex(unsigned int nbr, char up)
{
	put_hexa(nbr, up);
	return (h_digits(nbr));
}

static size_t	h_digits(unsigned int n)
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

static void	put_hexa(unsigned int nbr, char up)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (nbr >= 16)
		put_hexa((nbr / 16), up);
	if (up == 'X')
		write(1, &upper_digits[nbr % 16], 1);
	else
		write(1, &lower_digits[nbr % 16], 1);
}
