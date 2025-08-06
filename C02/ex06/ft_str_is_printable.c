int	ft_str_is_printable(char *str)
{
	char *s;

	s = str;
	while (*s)
	{
		if (*s < 32 || *s > 126)
			return (0);
		s++;
	}
	return (1);
}

// what it does: checks if all characters in str are printable ASCII (32–126)
// input: str = pointer to a null-terminated string
// output: 1 if str is empty or all characters printable, otherwise 0
// edge cases: empty string → 1; behavior undefined if str is NULL