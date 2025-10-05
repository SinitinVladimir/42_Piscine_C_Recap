// with malloc

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	if (!src)
		return (NULL);
	len = 0;
	while (src[len])
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

/*
what: allocate and return a duplicate of the c-string src
inputs: src -> null-terminated string
output: newly allocated copy (must be freed), or null on allocation failure
edge cases: src == null -> return null; empty string handled (allocates 1 byte)
*/






// Without malloc - but with a buffer


char	*ft_strdup(char *src)
{
	static char	buf[1024];
	int			i;

	if (!src)
		return (0);
	i = 0;
	while (src[i] && i < (int)sizeof(buf) - 1)
	{
		buf[i] = src[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

/*
what: duplicate string into a static internal buffer
inputs: src -> null-terminated string
output: pointer to internal static buffer with copy, or 0 if src is null
edge cases: capacity limited (1023 chars + '\0'); content is overwritten
            on next call; not thread-safe; do not free the returned pointer
*/