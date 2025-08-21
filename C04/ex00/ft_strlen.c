int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*s)
		s++;
	return ((int)(s - str));
}

/*
 * what it does: returns the length of a null-terminated string
 * inputs: str -> pointer to the string
 * output: number of characters before the '\0'
 * edge cases: str == NULL is undefined; empty string returns 0
 */
