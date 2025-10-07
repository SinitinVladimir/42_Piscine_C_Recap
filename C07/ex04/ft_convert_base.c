#include <stdlib.h>

/* helpers from ft_convert_base2.c */
int		ft_base_len(char *b);
long	ft_atol_base(char *str, char *base, int blen);
char	*ft_ltoa_base(long n, char *base, int blen);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		bl_from;
	int		bl_to;
	long	val;

	if (!nbr || !base_from || !base_to)
		return (0);
	bl_from = ft_base_len(base_from);
	bl_to = ft_base_len(base_to);
	if (!bl_from || !bl_to)
		return (0);
	val = ft_atol_base(nbr, base_from, bl_from);
	return (ft_ltoa_base(val, base_to, bl_to));
}

/*
what: convert number string from base_from to base_to
inputs: nbr (c-string), base_from, base_to (each: unique chars, len >= 2)
output: newly allocated string representing the value in base_to, or null
edges: ignores leading spaces, multiple signs; emits only one '-' if needed
       invalid bases -> null; the represented value must fit in an int by subject
*/