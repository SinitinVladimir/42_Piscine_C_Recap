int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*
what: compute factorial using recursion
input: nb (int)
output: factorial as int; returns 0 for negative nb
edge cases: 0! and 1! are 1; integer overflow for large nb is undefined