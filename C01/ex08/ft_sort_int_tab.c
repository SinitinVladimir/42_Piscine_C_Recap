/*
 * sorts an array of integers in ascending order using quicksort
 */
static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a  = *b;
	*b  = tmp;
}

static int	ft_partition(int *tab, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[(low + high) / 2];
	i = low;
	j = high;
	while (i <= j)
	{
		while (tab[i] < pivot)
			i++;
		while (tab[j] > pivot)
			j--;
		if (i <= j)
		{
			ft_swap(&tab[i], &tab[j]);
			i++;
			j--;
		}
	}
	return (i);
}

static void	ft_quicksort(int *tab, int low, int high)
{
	int	idx;

	if (low < high)
	{
		idx = ft_partition(tab, low, high);
		if (low < idx - 1)
			ft_quicksort(tab, low, idx - 1);
		if (idx < high)
			ft_quicksort(tab, idx, high);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	if (!tab || size <= 1)
		return ;
	ft_quicksort(tab, 0, size - 1);
}

// what it does: reorders the elements of tab[0..size-1] so they ascend
// input: tab = pointer to first element, size = number of elements
// output: the array is sorted in place; nothing is returned
// edge cases: if tab is null or size <= 1, the function does nothing
