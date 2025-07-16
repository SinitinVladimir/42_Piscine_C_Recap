#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
    /* entire reversed alphabet in one syscall */
    static const char rev_alpha[] = "zyxwvutsrqponmlkjihgfedcba";
    write(1, rev_alpha, sizeof(rev_alpha) - 1);
}
