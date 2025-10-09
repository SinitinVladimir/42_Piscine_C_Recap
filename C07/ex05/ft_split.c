/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Created: 2025/10/08                                    #+#    #+#        */
/*   Updated: 2025/10/08                                    ###   ########.fr */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_sep(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *s, char *set)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], set))
			i++;
		if (s[i])
			cnt++;
		while (s[i] && !is_sep(s[i], set))
			i++;
	}
	return (cnt);
}

static char	*dup_n(char *s, int len)
{
	char	*p;
	int		i;

	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static char	**free_tab(char **tab, int filled)
{
	while (--filled >= 0)
		free(tab[filled]);
	free(tab);
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		wc;
	int		i;
	int		k;
	int		start;

	wc = count_words(str, charset);
	tab = (char **)malloc((wc + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_sep(str[i], charset))
			i++;
		if (i > start)
		{
			tab[k] = dup_n(str + start, i - start);
			if (!tab[k++])
				return (free_tab(tab, k - 1));
		}
	}
	tab[k] = 0;
	return (tab);
}

/*
what: split string by any char in charset, skipping empty fields
input: str (source), charset (set of separators)
output: null-terminated array of freshly allocated substrings (or null on fail)
edge cases: empty str -> returns array with only NULL; charset empty -> whole
            string duplicated as a single field; allocation failure -> null
*/