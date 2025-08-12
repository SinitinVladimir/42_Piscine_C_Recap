#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	is_printable(unsigned char c)
{
	return (c >= 32 && c <= 126);
}

static void	put_hex_escape(unsigned char c)
{
	char			hex[16];
	char			out[2];

	/* "0123456789abcdef" split to keep line length small */
	hex[0] = '0'; hex[1] = '1'; hex[2] = '2'; hex[3] = '3';
	hex[4] = '4'; hex[5] = '5'; hex[6] = '6'; hex[7] = '7';
	hex[8] = '8'; hex[9] = '9'; hex[10] = 'a'; hex[11] = 'b';
	hex[12] = 'c'; hex[13] = 'd'; hex[14] = 'e'; hex[15] = 'f';
	out[0] = hex[c / 16];
	out[1] = hex[c % 16];
	write(1, "\\", 1);
	write(1, out, 2);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (is_printable(c))
			ft_putchar((char)c);
		else
			put_hex_escape(c);
		i++;
	}
}

/*
** does: writes str to stdout; non-printable bytes are replaced by "\xy"
**       where xy are lowercase hex digits of the byte value.
** in :  str (c string, may contain bytes 0..255)
** out:  no return; writes to fd 1 only
** edge: handles signed char safely via unsigned cast; '\0' ends output;
**       printable range is ascii 32..126 inclusive.
*/
