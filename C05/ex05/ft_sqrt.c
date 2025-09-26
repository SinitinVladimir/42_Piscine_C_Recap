int	ft_sqrt(int nb)
{
	int	lo;
	int	hi;
	int	mid;
	int	q;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	lo = 1;
	hi = nb / 2;
	if (hi < 1)
		hi = 1;
	if (hi > 46340)
		hi = 46340;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		q = nb / mid;
		if (q == mid && nb % mid == 0)
			return (mid);
		if (q < mid)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return (0);
}

/*
what: integer square root via binary search; returns exact root or 0
inputs: nb (int)
output: int perfect square root if nb is a perfect square, else 0
edge cases: nb<=0 -> 0; avoid overflow by using division (nb/mid) instead of mid*mid
*/