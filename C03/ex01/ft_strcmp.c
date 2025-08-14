#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return ((int)(*a) - (int)(*b));
}

/*
** compares two null-terminated strings lexicographically.
** in:  s1, s2
** out: negative/zero/positive like strcmp
** edge cases: handles empty strings; comparison stops at first diff or '\0';
**             bytes are treated as unsigned to avoid sign issues.
*/