char	*ft_strstr(char *str, char *to_find)
{
	char	*h;
	char	*n;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		h = str;
		n = to_find;
		while (*h && *n && (*h == *n))
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return (str);
		str++;
	}
	return (0);
}

/*
** what: find first occurrence of substring to_find inside str
** in : str (haystack), to_find (needle)
** out: pointer to first match in str, or 0 if not found
** edges: empty to_find → return str; no library calls; undefined for NULL args
*/
