int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

/*
 * does: converts leading part of str to int (base 10)
 * input: char *str (may start with spaces/tabs/newlines, then +/- signs, then digits)
 * output: resulting int
 * edge cases: multiple signs allowed (odd '-' -> negative); stops at first non-digit;
 *             ignores overflow/underflow per subject; empty or no digits -> 0
 */