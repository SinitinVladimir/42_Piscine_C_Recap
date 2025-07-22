#include <unistd.h>

static void	ft_write_buf(int comb[], int n, int last)
{
	char	buf[11];
	int		i;

	i = 0;
	while (i < n)
	{
		buf[i] = '0' + comb[i];
		i++;
	}
	if (last)
		write(1, buf, n);
	else
	{
		buf[n]     = ',';
		buf[n + 1] = ' ';
		write(1, buf, n + 2);
	}
}

static int	ft_is_last(int comb[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (comb[i] != (10 - n + i))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_increment(int comb[], int n)
{
	int	i;
	int	j;

	i = n - 1;
	while (i >= 0 && comb[i] == 10 - n + i)
		i--;
	comb[i]++;
	j = i + 1;
	while (j < n)
	{
		comb[j] = comb[j - 1] + 1;
		j++;
	}
}

void	ft_print_combn(int n)
{
	int	comb[9];
	int	i;

	if (n < 1 || n > 9)
		return ;
	i = 0;
	while (i < n)
	{
		comb[i] = i;
		i++;
	}
	while (1)
	{
		if (ft_is_last(comb, n))
		{
			ft_write_buf(comb, n, 1);
			break ;
		}
		ft_write_buf(comb, n, 0);
		ft_increment(comb, n);
	}
}
