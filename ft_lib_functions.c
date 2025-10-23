#include "printf.h"

static int	ft_intlen(long n);
static char	*ft_strdup(const char *s);

char	*ft_itoa(long n)
{
	int		i;
	int		minus;
	char	*istr;

	minus = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		minus = 1;
		n = n * (-1);
	}
	i = ft_intlen(n);
	istr = malloc(i + minus + 1);
	if (!istr)
		return (0);
	istr[i + minus] = '\0';
	while (--i + minus >= 0)
	{
		istr[i + minus] = (char)(n % 10) + 48;
		n = n / 10;
	}
	if (minus == 1)
		istr[0] = '-';
	return (istr);
}

static int	ft_intlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
static char	*ft_strdup(const char *s)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = malloc(ft_strlen(s) + 1);
	if (!s2)
		return (0);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}