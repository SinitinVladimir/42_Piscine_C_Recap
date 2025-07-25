void	ft_ultimate_div_mod(int *a, int *b)
{
	int	q;
	int	r;

	if (*b == 0)
		return ;
	q = *a / *b;
	r = *a % *b;
	*a = q;
	*b = r;
}
