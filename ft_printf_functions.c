/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmuller <stmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:04:42 by stmuller          #+#    #+#             */
/*   Updated: 2025/10/24 21:04:42 by stmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*s != '\0')
	{
		if (write(1, s, 1) == -1)
			return (-1);
		len++;
		s++;
	}
	return (len);
}

int	ft_putnbr(long nbr)
{
	int		len;
	char	*nbr_s;

	nbr_s = ft_itoa(nbr);
	len = ft_putstr(nbr_s);
	free(nbr_s);
	return (len);
}
