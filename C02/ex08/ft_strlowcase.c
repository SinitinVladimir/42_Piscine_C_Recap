char	*ft_strlowcase(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
			*s += 'a' - 'A';
		s++;
	}
	return (str);
}

/*
** what it does: converts every uppercase letter in str to lowercase
** input:  str -> pointer to a null-terminated string (modified in place)
** output: returns the same pointer str
** edge cases: empty string unchanged; passing NULL is undefined behavior
*/
