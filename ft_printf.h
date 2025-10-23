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
int		ft_putptr(void *ptr);
int		ft_putstr(char *s);
char	*ft_itoa(int n);

#endif