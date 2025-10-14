#include <stdlib.h>
#include "ft_stock_str.h"

static int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*p;

	len = ft_strlen(s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[len] = '\0';
	return (p);
}

static void	*free_tab(t_stock_str *tab, int last)
{
	while (last-- > 0)
		free(tab[last].copy);
	free(tab);
	return (NULL);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = (t_stock_str *)malloc((ac + 1) * sizeof(*tab));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if (!tab[i].copy)
			return (free_tab(tab, i));
		i++;
	}
	tab[i].size = 0;
	tab[i].str = NULL;
	tab[i].copy = NULL;
	return (tab);
}

/*
what it does: builds an array of structs {size, str, copy} from av,
             with a sentinel element at the end (all zeros)
inputs: ac = number of strings, av = array of strings
outputs: pointer to allocated t_stock_str array, or null on error
edge cases: ac can be 0 (returns only sentinel if malloc succeeds);
            allocation failure frees any previous copies and returns null
*/