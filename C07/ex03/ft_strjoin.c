#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

static int	join_calc_len(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	total += (size - 1) * ft_strlen(sep);
	return (total);
}

static void	copy_into(char *dst, const char *src, int *pos)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[*pos] = src[i];
		(*pos)++;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		pos;
	int		i;
	int		total;

	if (size <= 0)
	{
		res = (char *)malloc(1);
		if (res)
			res[0] = '\0';
		return (res);
	}
	total = join_calc_len(size, strs, sep);
	res = (char *)malloc((total + 1) * sizeof(char));
	if (!res)
		return (0);
	pos = 0;
	i = 0;
	while (i < size)
	{
		copy_into(res, strs[i], &pos);
		if (i < size - 1)
			copy_into(res, sep, &pos);
		i++;
	}
	res[pos] = '\0';
	return (res);
}

/*
what: concatenates all strings in strs with sep between, returns a new string
inputs: size (count of strings), strs (array of c-strings), sep (separator)
output: heap-allocated null-terminated string; "" if size<=0; null on malloc fail
edge cases: size<=0 -> empty string; empty sep or empty items ok; no overflow checks
*/