char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*d;
	unsigned int	i;

	d = dest;
	i = 0;
	/* copy up to n bytes or until src ends */
	while (i < n && *src)
	{
		*d++ = *src++;
		i++;
	}
	/* pad with zeros if src was shorter than n */
	while (i < n)
	{
		*d++ = '\0';
		i++;
	}
	return (dest);
}

// what it does: copies up to n characters from src into dest,
//                padding with '\\0' if src is shorter than n
// input: dest = destination buffer, src = source string, n = max characters
// output: returns dest (which holds the copied/padded string)
// edge cases: if src length < n, dest is zero-padded; src and dest must not overlap; behavior undefined if dest is NULL or too small
