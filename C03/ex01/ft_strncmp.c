
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	*b;

	if (n == 0)
		return (0);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (i < n && a[i] == b[i])
	{
		if (a[i] == '\0')
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return ((int)a[i] - (int)b[i]);
}

/*
** compares two strings lexicographically, at most n bytes.
** in:  s1, s2, n
** out: negative/zero/positive like strncmp
** edge cases: n == 0 → 0; stops early on '\0'; bytes are treated as unsigned.
*/