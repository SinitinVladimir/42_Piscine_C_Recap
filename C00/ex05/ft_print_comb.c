// // #include <unistd.h>

// // void ft_print_comb(void)
// // {
// //     char buf[5];
// //     int n = 012;  /* octal literal for 012 == decimal 10 */
// //     while (n <= 789)
// //     {
// //         int d = n / 100;
// //         int e = (n / 10) % 10;
// //         int f = n % 10;
// //         if (d < e && e < f)
// //         {
// //             buf[0] = '0' + d;
// //             buf[1] = '0' + e;
// //             buf[2] = '0' + f;
// //             if (n == 789)
// //                 write(1, buf, 3);
// //             else
// //             {
// //                 buf[3] = ',';
// //                 buf[4] = ' ';
// //                 write(1, buf, 5);
// //             }
// //         }
// //         n++;
// //     }
// // }


// #include <unistd.h>

// static void rec(char *buf, int pos, char last)
// {
//     if (pos == 3)
//     {
//         if (buf[0] == '7' && buf[1] == '8' && buf[2] == '9')
//             write(1, buf, 3);
//         else
//         {
//             buf[3] = ',';
//             buf[4] = ' ';
//             write(1, buf, 5);
//         }
//         return;
//     }
//     char c = last + 1;
//     while (c <= '9')
//     {
//         buf[pos] = c;
//         rec(buf, pos + 1, c);
//         c++;
//     }
// }

// void ft_print_comb(void)
// {
//     char buf[5];
//     rec(buf, 0, '0' - 1);
// }

#include <unistd.h>

void ft_print_comb(void)
{
    char buf[5];
    char d = '0';

    while (d <= '7')
    {
        char e = d + 1;
        while (e <= '8')
        {
            char f = e + 1;
            while (f <= '9')
            {
                buf[0] = d;
                buf[1] = e;
                buf[2] = f;
                if (d == '7' && e == '8' && f == '9')
                {
                    /* last combo: just “789” */
                    write(1, buf, 3);
                }
                else
                {
                    buf[3] = ',';
                    buf[4] = ' ';
                    write(1, buf, 5);
                }
                f++;
            }
            e++;
        }
        d++;
    }
}
