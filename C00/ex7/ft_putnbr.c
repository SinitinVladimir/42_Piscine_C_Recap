#include <unistd.h>

static void rec_put(long long n, char *buf, int *idx)
{
    if (n >= 10)
        rec_put(n/10, buf, idx);
    buf[(*idx)++] = '0' + (n % 10);
}

void ft_putnbr(int nb)
{
    char buf[12];
    int  i = 0;
    long long n = nb;

    if (n < 0) { buf[i++] = '-'; n = -n; }
    rec_put(n, buf, &i);
    write(1, buf, i);
}
