/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmuller <stmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:45:44 by stmuller          #+#    #+#             */
/*   Updated: 2025/10/23 20:45:44 by stmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(char const *str, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nbr);
int		ft_put_hex(unsigned int nbr, char up);
int		ft_put_ptr(void *ptr);
int		ft_putstr(char *s);
char	*ft_itoa(long n);

#endif