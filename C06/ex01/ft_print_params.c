#include <unistd.h>

static void	ft_putendl(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (len)
		write(1, s, len);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		i++;
	}
	return (0);
}

/*
what: prints each program argument (except argv[0]) on its own line
inputs: argc/argv from main
output: writes arguments to stdout using write
edge cases: no extra args -> prints nothing; handles empty strings as blank lines
*/