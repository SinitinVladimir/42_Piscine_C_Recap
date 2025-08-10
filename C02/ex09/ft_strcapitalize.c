char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		if (new_word && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 'a' - 'A';
			new_word = 0;
		}
		else if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'a' && str[i] <= 'z'))
			new_word = 0;
		else
			new_word = 1;
		i++;
	}
	return (str);
}

/*
** does: capitalize first letter of each alphanumeric word, lowercase others
** in : str (modifiable c string)
** out: returns same pointer str after in-place changes
** edge: empty string ok; non-ascii unchanged; digit can start a word
*/