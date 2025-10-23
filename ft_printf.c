#include "ft_printf.h"

static int	checker(const char toCheck, va_list args)
{
	if (toCheck == 'c')
		return(ft_putchar(va_arg(args, int)));
	else if (toCheck == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if ((toCheck == 'i') || (toCheck == 'd'))
		return (ft_putnbr(va_arg(args, int)));
	else if (toCheck == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (toCheck == 'x' || toCheck == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), toCheck));
	else if (toCheck == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (toCheck == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		len;
	int		check;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check =  checker(*(++str), args);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			check = write(1, str, 1);
			if (check == -1)
				return (-1);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}