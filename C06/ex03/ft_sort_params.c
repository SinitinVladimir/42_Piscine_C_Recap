#include <unistd.h>

/* write s then a newline using only write */
static void	ft_putendl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i)
		write(1, s, i);
	write(1, "\n", 1);
}

/* classic strcmp: lexicographic compare, unsigned char semantics */
static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
		ft_putendl(argv[i++]);
	return (0);
}

/*
what: sort program arguments (excluding argv[0]) by ascii and print one per line
inputs: argc/argv from main
output: each argument written to stdout followed by '\n'
edge cases: argc <= 1 prints nothing; empty strings print blank lines;
            sorting is stable enough for this exercise; only write is used
*/