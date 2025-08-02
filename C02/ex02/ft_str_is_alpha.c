int	ft_str_is_alpha(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		if (!((*s >= 'A' && *s <= 'Z')
		   || (*s >= 'a' && *s <= 'z')))
			return (0);
		s++;
	}
	return (1);
}

// what it does: checks if all characters in str are letters a–z or A–Z
// input: str = pointer to a null-terminated string
// output: returns 1 if str is empty or only letters, otherwise 0
// edge cases: empty string → 1; non-letter byte returns 0; passing NULL is undefined
