static int	pow_rec(int nb, int p)
{
	int	half;

	if (p == 0)
		return (1);
	if (p == 1)
		return (nb);
	if ((p & 1) == 0)
	{
		half = pow_rec(nb, p / 2);
		return (half * half);
	}
	return (nb * pow_rec(nb, p - 1));
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (pow_rec(nb, power));
}

/*
what: compute nb raised to power using recursive exponentiation by squaring
input: nb (int), power (int)
output: int result; returns 0 for negative power; 1 for power == 0
edge cases: 0^0 returns 1 by convention; potential integer overflow for large results