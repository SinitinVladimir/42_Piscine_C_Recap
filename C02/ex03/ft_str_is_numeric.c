int	ft_str_is_numeric(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

// what it does: returns 1 if every character in str is between '0' and '9'
// input: str = pointer to a null-terminated string
// output: 1 if str is empty or contains only digits, otherwise 0
// edge cases: empty string -> 1; behavior undefined if str is NULL
