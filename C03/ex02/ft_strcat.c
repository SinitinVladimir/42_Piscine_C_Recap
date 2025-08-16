int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*s)
		s++;
	return ((int)(s - str));
}

char	*ft_strcat(char *dest, char *src)
{
	char	*d;
	char	*s;

	d = dest;
	while (*d)
		d++;
	s = src;
	while (*s)
		*d++ = *s++;
	*d = '\0';
	return (dest);
}

/*
** ft_strlen: returns length of null-terminated str (in: str → out: length)
** ft_strcat: appends src to end of dest and returns dest.
** inputs: dest (nul-terminated, enough space), src (nul-terminated)
** outputs: pointer to dest
** edge cases: dest/src must not be NULL; no size check (unlike strlcat);
**             behavior is undefined if buffers overlap or dest lacks space.
*/