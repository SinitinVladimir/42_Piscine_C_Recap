#include <unistd.h>

/*
 * Writes the entire string str to stdout in one syscall.
 * Faster than per-character writes.
 */
void	ft_putstr(char *str)
{
	int	len;

	/* compute string length */
	len = 0;
	while (str[len])
		len++;

	/* write all bytes at once */
	write(1, str, len);
}


// void	ft_putstr(char *str)
// {
// 	while (*str)
// 		write(1, str++, 1);
// }