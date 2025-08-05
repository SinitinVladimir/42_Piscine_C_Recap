int	ft_str_is_uppercase(char *str)
{
	char *s;

	s = str;
	while (*s)
	{
		if (*s < 'A' || *s > 'Z')
			return (0);
		s++;
	}
	return (1);
}

// what it does: returns 1 if str is empty or all characters are 'A'–'Z'
// input: str = pointer to a null-terminated string
// output: 1 if every character is uppercase or str is empty, otherwise 0
// edge cases: empty string → 1; behavior undefined if str is NULL
