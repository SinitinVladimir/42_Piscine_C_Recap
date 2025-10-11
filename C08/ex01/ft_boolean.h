#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef int	t_bool;

# define TRUE 1
# define FALSE 0

/* evaluates to 1 when nbr is even, 0 otherwise (no ternary) */
# define EVEN(nbr) (((nbr) % 2) == 0)

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG  "I have an odd number of arguments.\n"
# define SUCCESS  0

#endif
/* what: header defining boolean type/macros used in the module
input: none
output: n/a
edge cases: EVEN fully parenthesized, no ternary; safe as expression macro */