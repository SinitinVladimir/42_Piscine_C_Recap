#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* return base length if valid, 0 otherwise */
static int	ft_base_len_if_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

static void	ft_putnbr_base_u(unsigned int n, char *base, unsigned int blen)
{
	if (n >= blen)
		ft_putnbr_base_u(n / blen, base, blen);
	ft_putchar(base[n % blen]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				blen;
	unsigned int	un;

	blen = ft_base_len_if_valid(base);
	if (!blen)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		un = (unsigned int)(-(long)nbr);
	}
	else
		un = (unsigned int)nbr;
	ft_putnbr_base_u(un, base, (unsigned int)blen);
}

/*
what: print integer nbr using the digit set given by base
input: nbr (int), base (string of unique printable chars, no '+' or '-')
output: none (writes to stdout)
edge cases: invalid base (len < 2, duplicates, non-printable or '+','-') -> prints nothing;
            handles int min safely by converting through long to unsigned
*/