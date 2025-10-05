#include <stdlib.h>

/*
** ex02: allocate and fill *range with the integers [min, max)
** return the number of elements, 0 if min >= max, and -1 on malloc failure
** note: if min >= max => *range is set to NULL as required by the subject
*/
int	ft_ultimate_range(int **range, int min, int max)
{
	int		len;
	int		i;
	int		*arr;

	if (!range)
		return (-1);
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	arr = (int *)malloc((size_t)len * sizeof(int));
	if (!arr)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (len);
}

/*
what: allocates array with values from min (inclusive) to max (exclusive)
inputs: range (output pointer), min, max
output: number of elements; 0 if empty range; -1 on allocation failure
edge cases: range==NULL -> -1; min>=max -> *range=NULL, return 0; malloc fail -> -1
*/