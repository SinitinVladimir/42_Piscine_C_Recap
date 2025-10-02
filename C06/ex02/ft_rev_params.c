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

	i = argc - 1;
	while (i > 0)
	{
		ft_putendl(argv[i]);
		i--;
	}
	return (0);
}

/*
what: prints all program arguments in reverse order, one per line
inputs: argc/argv from main
output: writes each argument followed by newline to stdout
edge cases: no extra args -> prints nothing; empty strings print blank lines
*/