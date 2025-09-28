int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i <= nb / i)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (nb < 2147483647 && !ft_is_prime(nb))
		nb += 2;
	return (nb);
}

/*
ft_is_prime:
  what: primality test using 6k±1 step and sqrt bound
  inputs: nb (int)
  output: 1 if prime, 0 otherwise
  edge cases: nb<=1 -> 0; 2 and 3 -> 1; avoids overflow via i <= nb / i

ft_find_next_prime:
  what: returns nb if prime, else the next prime >= nb
  inputs: nb (int)
  output: next prime as int
  edge cases: nb<=2 -> 2; even nb -> nb+1 checked; loops by +2 over odds;
  capped at int max (2147483647, which is prime)
*/