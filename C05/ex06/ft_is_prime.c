int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i <= nb / i)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

/*
what: primality test using 6k±1 checks and sqrt bound
inputs: nb (int)
output: 1 if prime, 0 otherwise
edge cases: nb<=1 -> 0; 2 and 3 -> 1; avoids overflow via i <= nb / i
*