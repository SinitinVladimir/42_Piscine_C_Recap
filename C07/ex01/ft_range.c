#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long	diff;
	size_t	len;
	int		*arr;
	int		*p;

	diff = (long)max - (long)min;
	if (diff <= 0)
		return (0);
	len = (size_t)diff;
	arr = (int *)malloc(len * sizeof(int));
	if (!arr)
		return (0);
	p = arr;
	while (min < max)
		*p++ = min++;
	return (arr);
}

/*
what: allocate and fill an int array with values [min, max)
inputs: min, max (ints)
output: pointer to array of length (max - min) or 0 on error/empty range
edge cases: min >= max -> 0; allocation failure -> 0; large ranges handled
            by using size_t for byte count; do not forget to free the array
*/