
int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	base;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = 1;
	base = nb;
	while (power > 0)
	{
		if (power & 1)
			result *= base;
		base *= base;
		power /= 2;
	}
	return (result);
}

/*
what: compute nb raised to power using fast iterative exponentiation
input: nb (int), power (int)
output: int result; returns 0 for negative power, 1 for power == 0
edge cases: 0^0 returns 1 by convention; integer overflow for large results is undefined