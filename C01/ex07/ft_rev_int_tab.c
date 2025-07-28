void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

// what it does: reverses the contents of an int array in place
// input: tab = pointer to the first element, size = number of elements
// output: the order of elements in tab is flipped
// edge cases: if size <= 1 nothing changes; passing a null tab is undefined behavior
