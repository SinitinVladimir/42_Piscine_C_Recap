unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dlen;
	unsigned int	slen;
	unsigned int	i;

	/* measure dest, but never read past size */
	dlen = 0;
	while (dlen < size && dest[dlen] != '\0')
		dlen++;
	/* measure src fully */
	slen = 0;
	while (src[slen] != '\0')
		slen++;
	/* if no space to append, return size + src length */
	if (dlen == size)
		return (size + slen);
	/* append as much as fits, keeping room for the null terminator */
	i = 0;
	while (src[i] != '\0' && (dlen + i + 1) < size)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}

/*
 * what it does: appends src to dest with total buffer limit 'size'
 * inputs: dest (destination buffer), src (string to append), size (full
 *         size of dest buffer, including space for '\0')
 * output: returns the length it tried to create: initial length of dest
 *         (clamped to size) plus length of src
 * edge cases: size == 0 (no write, returns src length); size <= current
 *             dest length (no append, returns size + src length);
 *             overlapping buffers are undefined like the real strlcat
 */