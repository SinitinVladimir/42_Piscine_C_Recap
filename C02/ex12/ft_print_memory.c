#include <unistd.h>

static void	putchar_hex(unsigned char b)
{
	char			hex[2];
	const char		*digits = "0123456789abcdef";

	hex[0] = digits[b >> 4];
	hex[1] = digits[b & 0x0F];
	write(1, hex, 2);
}

static void	print_address(void *p)
{
	unsigned long long	val;
	char				buf[16];
	int					i;
	const char			*digits = "0123456789abcdef";

	val = (unsigned long long)p;
	i = 16;
	while (i--)
	{
		buf[i] = digits[val & 0x0F];
		val >>= 4;
	}
	write(1, buf, 16);
	write(1, ": ", 2);
}

static void	print_hex_line(unsigned char *line, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < len)
			putchar_hex(line[i]);
		else
			write(1, "  ", 2);
		if ((i & 1) == 1)
			write(1, " ", 1);
		i++;
	}
}

static void	print_ascii_line(unsigned char *line, unsigned int len)
{
	unsigned int	i;
	char			ch;

	i = 0;
	while (i < len)
	{
		ch = (line[i] >= 32 && line[i] <= 126) ? (char)line[i] : '.';
		write(1, &ch, 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		offset;
	unsigned int		chunk;
	unsigned char		*ptr;

	ptr = (unsigned char *)addr;
	offset = 0;
	while (offset < size)
	{
		chunk = (size - offset >= 16) ? 16 : (size - offset);
		print_address(ptr + offset);
		print_hex_line(ptr + offset, chunk);
		print_ascii_line(ptr + offset, chunk);
		write(1, "\n", 1);
		offset += 16;
	}
	return (addr);
}

/*
* prints a hex/ascii dump of memory starting at addr, 16 bytes per line.
* input:  addr (void*), size (bytes to display)
* output: returns addr; writes formatted dump to stdout
* edge cases: size == 0 prints nothing; last line padded in hex column;
*             non-printables shown as '.'; address shown as 16 lowercase hex.
*/