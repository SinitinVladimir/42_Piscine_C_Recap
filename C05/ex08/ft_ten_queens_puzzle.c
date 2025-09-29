#include <unistd.h> /* allowed: write */

static void	print_solution(int pos[10])
{
	int		i;
	char	out[11];

	i = 0;
	while (i < 10)
	{
		out[i] = (char)(pos[i] + '0');
		i++;
	}
	out[10] = '\n';
	write(1, out, 11);
}

static void	solve(int col, int pos[10], int row[10],
					int d1[19], int d2[19], int *cnt)
{
	int	r;
	int	a;
	int	b;

	if (col == 10)
	{
		print_solution(pos);
		(*cnt)++;
		return ;
	}
	r = 0;
	while (r < 10)
	{
		a = r - col + 9;
		b = r + col;
		if (!row[r] && !d1[a] && !d2[b])
		{
			row[r] = 1;
			d1[a] = 1;
			d2[b] = 1;
			pos[col] = r;
			solve(col + 1, pos, row, d1, d2, cnt);
			row[r] = 0;
			d1[a] = 0;
			d2[b] = 0;
		}
		r++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	pos[10];
	int	row[10];
	int	d1[19];
	int	d2[19];
	int	i;
	int	count;

	i = 0;
	while (i < 10)
		row[i++] = 0;
	i = 0;
	while (i < 19)
	{
		d1[i] = 0;
		d2[i] = 0;
		i++;
	}
	count = 0;
	solve(0, pos, row, d1, d2, &count);
	return (count);
}

/*
what: prints every valid configuration of 10 queens (one digit per column),
      then returns the total number of solutions
inputs: none
output: number of printed solutions (int)
edge cases: none specific; uses 6k±1-like pruning via diagonal masks,
            diagonal indices are shifted to stay non-negative ([-9..9] -> [0..18])
*/