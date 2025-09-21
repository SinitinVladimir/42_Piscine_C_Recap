int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	res = 1;
	while (nb > 1)
	{
		res *= nb;
		nb--;
	}
	return (res);
}

/*
what: compute factorial iteratively
input: nb (int)
output: factorial as int; returns 0 for negative nb
edge cases: 0! and 1! return 1; overflow for big nb is undefined (wraps in int)