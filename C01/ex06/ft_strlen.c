/*
 * Returns the length of the null‑terminated string str.
 * Uses pointer arithmetic for minimal overhead.
 */
int ft_strlen(char *str)
{
    char *s;

    s = str;
    while (*s)
        s++;
    return (int)(s - str);
}

// what it does: returns number of characters before '\0'
// input: pointer to a null-terminated string
// output: length of the string as int (excluding the null)
// edge cases: empty string returns 0; passing null pointer is undefined
