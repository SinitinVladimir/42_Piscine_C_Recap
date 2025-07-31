char	*ft_strcpy(char *dest, char *src)
{
	char	*d;

	d = dest;
	while (*src)
	{
		*d = *src;
		d++;
		src++;
	}
	*d = '\0';
	return (dest);
}

// what it does: copies the null-terminated string src into dest
// input: dest = pointer to buffer (must be large enough), src = source string
// output: returns dest, which now holds a copy of src
// edge cases: src must be a valid string; dest and src must not overlap; behavior undefined if dest is too small or src is NULL