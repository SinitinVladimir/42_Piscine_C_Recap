unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	if (size != 0)
	{
		i = 0;
		while (i + 1 < size && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[len] != '\0')
		len++;
	return (len);
}

/*
** does: copy up to size-1 chars from src to dest and null-terminate if size>0
** in : dest (buffer), src (c string), size (dest capacity in bytes)
** out: returns length of src (not number of bytes copied)
** edge: size==0 leaves dest untouched; no support for overlapping buffers
*/
