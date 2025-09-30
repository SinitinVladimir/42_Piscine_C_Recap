#include <unistd.h>

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc >= 1 && argv && argv[0])
		write(1, argv[0], ft_strlen(argv[0]));
	write(1, "\n", 1);
	return (0);
}

/*
what: prints the program name followed by a newline
inputs: argc/argv (uses argv[0])
output: none (writes to stdout), returns 0
edge cases: argc is always >= 1 by standard; extra null checks keep it safe
*/