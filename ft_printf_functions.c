#include "ft_printf.h"

int ft_putchar(char c)
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

int ft_putnbr(int nbr)
{
	int		len;
	char	*nbr_s;

	nbr_s = ft_itoa(nbr);
	len = ft_putstr(nbr_s);
	free(nbr_s);
	return (len);
}