#ifndef FT_ABS_H
# define FT_ABS_H

/*
** absolute value macro
** note: fully parenthesized to avoid precedence bugs.
** beware of side effects in Value (e.g. i++) and of INT_MIN negation overflow.
*/
# define ABS(Value) (((Value) < 0) ? -(Value) : (Value))

#endif