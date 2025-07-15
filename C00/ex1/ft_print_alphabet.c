#include <unistd.h>

void ft_print_alphabet(void)
{
    /* Write all 26 letters in one syscall */
    static const char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    write(1, alpha, sizeof(alpha) - 1);
}
//