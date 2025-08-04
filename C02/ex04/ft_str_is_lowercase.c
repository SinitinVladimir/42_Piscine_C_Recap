int	ft_str_is_lowercase(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		if (*s < 'a' || *s > 'z')
			return (0);
		s++;
	}
	return (1);
}

// what it does: returns 1 if str contains only lowercase letters (a–z)
// input: str = pointer to a null-terminated string
// output: 1 if str is empty or all lowercase, otherwise 0
// edge cases: empty string → 1; behavior undefined if str is NULL
