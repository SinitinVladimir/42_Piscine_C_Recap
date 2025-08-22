#include <unistd.h>

void	ft_putstr(char *str)
{
	char	*s;

	if (!str)
		return ;
	s = str;
	while (*s)
		s++;
	if (s != str)
		write(1, str, (unsigned long)(s - str));
}

/*
 * what it does: writes the whole null-terminated string to stdout
 * inputs: str -> pointer to the string
 * output: none
 * edge cases: str == NULL -> no output; empty string prints nothing
 */