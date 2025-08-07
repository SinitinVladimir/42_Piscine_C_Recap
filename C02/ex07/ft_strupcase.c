char	*ft_strupcase(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 'a' - 'A';
		s++;
	}
	return (str);
}

// what it does: converts every lowercase letter in str to uppercase
// input: str = pointer to a null-terminated string
// output: returns str, modified in place with 'a'–'z' → 'A'–'Z'
// edge cases: empty string remains unchanged; passing NULL is undefined behavior
