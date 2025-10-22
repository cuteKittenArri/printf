#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	checker(const char toCheck, va_list args)
{
	if (toCheck == 'c')
		return(ft_putchar(va_arg(args, int)));
	else if

	
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
		if (*str == %)
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