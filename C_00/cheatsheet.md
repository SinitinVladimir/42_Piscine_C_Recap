````markdown
# C00 Cheat Sheet

**Summary:**  
The **C00** module from 42’s Piscine introduces basic C functions for character and number output along with simple combinatorial logic. It covers **9 exercises** (ex00–ex08), each implemented with only the allowed `write` function and loops. Use this guide to understand each function’s prototype, implementation strategy, and common pitfalls—ensuring POSIX compliance and correct Moulinette output. ([scribd.com](https://www.scribd.com/document/558629305/en-subject-C00))

---

## Prerequisites & Rules

- **Allowed function:** only `write` from `<unistd.h>`.  
- **No other library** (e.g., no `printf`, no `stdlib.h`).  
- **Script header:** Include prototypes in `.c` files, e.g.:  
  ```c
  void ft_putchar(char c);
````

* **Compile:** `gcc -Wall -Wextra -Werror` (no warnings).
* **Style:** follow 42’s Norminette style guide strictly.

---

## Exercise Index  ([github.com](https://github.com/nataliakzm/School42_Piscine))

| Ex | Function Name               | Prototype                               | Description                                          |
| -- | --------------------------- | --------------------------------------- | ---------------------------------------------------- |
| 00 | `ft_putchar`                | `void ft_putchar(char c);`              | Write a single character                             |
| 01 | `ft_print_alphabet`         | `void ft_print_alphabet(void);`         | Print lowercase alphabet (`a`–`z`)                   |
| 02 | `ft_print_reverse_alphabet` | `void ft_print_reverse_alphabet(void);` | Print lowercase alphabet in reverse (`z`–`a`)        |
| 03 | `ft_print_numbers`          | `void ft_print_numbers(void);`          | Print digits `0`–`9`                                 |
| 04 | `ft_is_negative`            | `void ft_is_negative(int n);`           | Print `P` if `n>=0`, else `N`                        |
| 05 | `ft_print_comb`             | `void ft_print_comb(void);`             | Print all unique combinations of three digits        |
| 06 | `ft_print_comb2`            | `void ft_print_comb2(void);`            | Print all unique two-number combos from `00` to `99` |
| 07 | `ft_putnbr`                 | `void ft_putnbr(int nb);`               | Print integer (handle negatives)                     |
| 08 | `ft_print_combn`            | `void ft_print_combn(int n);`           | Print combinations of `n` distinct digits            |

---

## Detailed Implementations

### 00 `ft_putchar`

```c
#include <unistd.h>
void ft_putchar(char c) {
    write(1, &c, 1);
}
```

* **Key:** uses `write` syscall to file descriptor 1 (stdout). ([scribd.com](https://www.scribd.com/document/558629305/en-subject-C00))

### 01 `ft_print_alphabet`

```c
#include <unistd.h>
void ft_putchar(char c);
void ft_print_alphabet(void) {
    char c = 'a';
    while (c <= 'z') {
        ft_putchar(c);
        c++;
    }
}
```

* **Loop** from ASCII `97` to `122`. ([medium.com](https://medium.com/%40axellee1994/42-piscine-how-to-tackle-c00-ex01-57e9bdcd6138))

### 02 `ft_print_reverse_alphabet`

```c
#include <unistd.h>
void ft_putchar(char c);
void ft_print_reverse_alphabet(void) {
    char c = 'z';
    while (c >= 'a') {
        ft_putchar(c);
        c--;
    }
}
```

* **Reverse iteration**; watch unsigned char pitfalls (use `char`). ([medium.com](https://medium.com/%40axellee1994/42-piscine-how-to-tackle-c00-ex02-7dbd2d1c2db9))

### 03 `ft_print_numbers`

```c
#include <unistd.h>
void ft_putchar(char c);
void ft_print_numbers(void) {
    char c = '0';
    while (c <= '9') {
        ft_putchar(c);
        c++;
    }
}
```

* **Digits** ASCII `48`–`57`. ([github.com](https://github.com/nataliakzm/School42_Piscine))

### 04 `ft_is_negative`

```c
#include <unistd.h>
void ft_putchar(char c);
void ft_is_negative(int n) {
    if (n < 0)
        ft_putchar('N');
    else
        ft_putchar('P');
}
```

* **Conditional** output. ([github.com](https://github.com/nataliakzm/School42_Piscine))

### 05 `ft_print_comb`

```c
#include <unistd.h>
void ft_putchar(char c);
void ft_print_comb(void) {
    int x, y, z;
    for (x = 0; x <= 7; x++) {
        for (y = x + 1; y <= 8; y++) {
            for (z = y + 1; z <= 9; z++) {
                ft_putchar(x + '0');
                ft_putchar(y + '0');
                ft_putchar(z + '0');
                if (x != 7 || y != 8 || z != 9) {
                    ft_putchar(',');
                    ft_putchar(' ');
                }
            }
        }
    }
}
```

* **Three nested loops** ensure `x<y<z`. ([scribd.com](https://www.scribd.com/document/558629305/en-subject-C00))

### 06 `ft_print_comb2`

```c
#include <unistd.h>
void ft_putchar(char c);
void ft_print_comb2(void) {
    int a, b;
    for (a = 0; a <= 98; a++) {
        for (b = a + 1; b <= 99; b++) {
            ft_putchar((a / 10) + '0');
            ft_putchar((a % 10) + '0');
            ft_putchar(' ');
            ft_putchar((b / 10) + '0');
            ft_putchar((b % 10) + '0');
            if (a != 98 || b != 99) {
                ft_putchar(',');
                ft_putchar(' ');
            }
        }
    }
}
```

* **Double loops** for two-digit combos. ([github.com](https://github.com/nataliakzm/School42_Piscine))

### 07 `ft_putnbr`

```c
#include <unistd.h>
void ft_putchar(char c);
void ft_putnbr(int nb) {
    long n = nb;
    if (n < 0) {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    ft_putchar((n % 10) + '0');
}
```

* **Handle negative** by casting to `long`. **Recursive** output. ([github.com](https://github.com/rossattism/42.Piscine))

### 08 `ft_print_combn`

```c
#include <unistd.h>
void ft_putchar(char c);
void ft_print_combn(int n) {
    char buffer[10];
    int i;
    void recurse(int pos, int start) {
        if (pos == n) {
            for (i = 0; i < n; i++)
                ft_putchar(buffer[i]);
            if (buffer[0] != '0' + 10 - n)
                ft_putchar(',');
            ft_putchar(' ');
            return;
        }
        for (i = start; i <= 10 - n + pos; i++) {
            buffer[pos] = '0' + i;
            recurse(pos + 1, i + 1);
        }
    }
    recurse(0, 0);
}
```

* **Backtracking** for combinations of length `n`. ([scribd.com](https://www.scribd.com/document/558629305/en-subject-C00))

---

## Common Pitfalls

* **Trailing Separator:** Avoid extra comma+space after last element.
* **Unsigned char loops:** Use `char` or `int` for backward loops.
* **Function prototypes:** Must match exactly (return type & parameters).
* **No dynamic memory:** static buffers only.
* **Recursion depth:** For `ft_print_combn`, `n` max is 9.

---

* *\`\`\`
