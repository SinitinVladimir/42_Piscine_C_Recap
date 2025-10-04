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






// Without malloc


