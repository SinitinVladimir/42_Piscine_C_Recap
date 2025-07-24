#include <unistd.h>

void ft_print_comb2(void)
{
    char buf[7];
    int f = 0;

    while (f <= 98)
    {
        int s = f + 1;
        while (s <= 99)
        {
            /* first number */
            buf[0] = '0' + (f / 10);
            buf[1] = '0' + (f % 10);
            buf[2] = ' ';
            /* second number */
            buf[3] = '0' + (s / 10);
            buf[4] = '0' + (s % 10);

            if (f == 98 && s == 99)
            {
                /* last combo: "98 99" (5 bytes) */
                write(1, buf, 5);
            }
            else
            {
                /* all others: "XY UV, " (7 bytes) */
                buf[5] = ',';
                buf[6] = ' ';
                write(1, buf, 7);
            }
            s++;
        }
        f++;
    }
}
