char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*d;

	d = dest;
	while (*d)
		d++;
	while (*src && nb > 0)
	{
		*d++ = *src++;
		nb--;
	}
	*d = '\0';
	return (dest);
}

/*
** what: append at most nb bytes from src to end of dest, then nul-terminate
** in : dest (nul-terminated, enough space), src (nul-terminated), nb (limit)
** out: returns dest
** edges: nb==0 → dest unchanged; dest must have room; overlapping is ub
*/
