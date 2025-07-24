#include <unistd.h>

/* 
 * static inline — gives the compiler permission to substitute this code
 * directly at each call site, eliminating a real function call. 
 */
static inline void ft_putchar(char c)
{
    /* write to stdout (fd = 1), ignoring the return value */
    (void)!write(1, &c, 1);
}
