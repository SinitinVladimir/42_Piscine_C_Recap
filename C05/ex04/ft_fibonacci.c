int	ft_fibonacci(int index)
{
	int	a;
	int	b;
	int	i;
	int	next;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	a = 0;
	b = 1;
	i = 1;
	while (i < index)
	{
		next = a + b;
		a = b;
		b = next;
		i++;
	}
	return (b);
}

/*
what: compute fibonacci(index) iteratively in o(n) time, o(1) space
inputs: index (int)
output: nth fibonacci as int; -1 for negative index
edge cases: fib(0)=0, fib(1)=1; integer overflow for large index values
*/