static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

/* return base length if valid, 0 otherwise */
static int	base_len_if_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

static int	index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;
	int	blen;
	int	d;

	blen = base_len_if_valid(base);
	if (!blen)
		return (0);
	i = 0;
	while (is_space(str[i]))
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	res = 0;
	while ((d = index_in_base(str[i], base)) >= 0)
	{
		res = res * blen + d;
		i++;
	}
	return (sign * res);
}

/*
what: convert a string number written in an arbitrary base to int
input: str (string with optional whitespaces and +/-), base (unique chars, len>=2, no whitespaces, '+' or '-')
output: converted value as int; returns 0 if base is invalid
edge cases: multiple leading signs handled (odd number of '-' -> negative),
            stops conversion at first non-base char, overflow is undefined by subject
*/





/*  more elegant maybe -->*/


// static int	is_space(char c)
// {
// 	return (c == ' ' || (c >= 9 && c <= 13));
// }

// /* build fast lookup for base: map[c] -> digit index, or -1 if not in base.
//    returns base length when valid, 0 otherwise */
// static int	build_map(char *base, int map[256])
// {
// 	int				i;
// 	int				len;
// 	unsigned char	u;

// 	i = 0;
// 	while (i < 256)
// 	{
// 		map[i] = -1;
// 		i++;
// 	}
// 	len = 0;
// 	i = 0;
// 	while (base[i])
// 	{
// 		u = (unsigned char)base[i];
// 		if (base[i] == '+' || base[i] == '-' || is_space(base[i]) || map[u] != -1)
// 			return (0);
// 		map[u] = len++;
// 		i++;
// 	}
// 	if (len < 2)
// 		return (0);
// 	return (len);
// }

// int	ft_atoi_base(char *str, char *base)
// {
// 	int	map[256];
// 	int	blen;
// 	int	sign;
// 	int	res;
// 	int	digit;

// 	blen = build_map(base, map);
// 	if (!blen)
// 		return (0);
// 	while (is_space(*str))
// 		str++;
// 	sign = 1;
// 	while (*str == '+' || *str == '-')
// 	{
// 		if (*str == '-')
// 			sign = -sign;
// 		str++;
// 	}
// 	res = 0;
// 	digit = map[(unsigned char)*str];
// 	while (digit != -1)
// 	{
// 		res = res * blen + digit;
// 		str++;
// 		digit = map[(unsigned char)*str];
// 	}
// 	return (sign * res);
// }

// /*
// what: convert string in arbitrary valid base to int (like atoi but with base)
// input: str (may start with spaces and a run of +/-), base (unique chars, len>=2,
// no spaces and no +/-)
// output: int value of the parsed prefix; 0 if base invalid
// edge cases: multiple signs handled (odd '-' => negative), stops at first char not
//             in base; overflow/underflow behavior is unspecified per subject
// */