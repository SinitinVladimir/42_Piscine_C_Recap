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
