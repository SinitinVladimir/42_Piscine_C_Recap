#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = (long)nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr((int)(n / 10));
	ft_putchar((char)('0' + (n % 10)));
}

/*
 * what it does: prints an int to stdout using only write
 * input: nb (any 32-bit int)
 * output: none (side effect: writes characters to fd 1)
 * edge cases: handles 0; handles int_min by widening to long; prints '-' for negatives
 */