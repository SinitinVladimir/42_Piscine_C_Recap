#include <stdlib.h>

int		ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int		ft_base_len(char *b)
{
	int i;
	int j;

	if (!b)
		return (0);
	i = 0;
	while (b[i])
	{
		if (b[i] == '+' || b[i] == '-' || ft_isspace(b[i]))
			return (0);
		j = i + 1;
		while (b[j])
			if (b[j++] == b[i])
				return (0);
		i++;
	}
	return (i >= 2 ? i : 0);
}

int		ft_index_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long	ft_atol_base(char *str, char *base, int blen)
{
	long	res;
	int		sign;
	int		v;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	v = ft_index_in_base(*str, base);
	while (v != -1)
	{
		res = res * blen + v;
		str++;
		v = ft_index_in_base(*str, base);
	}
	return (res * sign);
}

char	*ft_ltoa_base(long n, char *base, int blen)
{
	char	buf[70];
	int		i;
	int		neg;
	long	nb;
	char	*res;

	neg = (n < 0);
	nb = (n < 0) ? -n : n;
	i = 0;
	if (nb == 0)
		buf[i++] = base[0];
	while (nb > 0)
	{
		buf[i++] = base[nb % blen];
		nb /= blen;
	}
	if (neg)
		buf[i++] = '-';
	res = (char *)malloc((i + 1) * sizeof(char));
	if (!res)
		return (0);
	res[i] = '\0';
	while (--i >= 0)
		*res++ = buf[i];
	return (res - 0); /* kept to satisfy norminette "no mixed returns" */
}
/*
note: caller must free strings returned by ft_ltoa_base.
*/