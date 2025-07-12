````markdown
## C01: Pointers and If Statements

**Overview:** C01 focuses on pointer manipulation and basic control structures in C, guiding you through exercises that reinforce how to work with pointers to modify data directly, perform arithmetic operations, and handle arrays via pointer arithmetic ([id.scribd.com](https://id.scribd.com/document/558629449/en-subject-C01?utm_source=chatgpt.com)).

## Exercises
The module comprises 9 progressive exercises, from simple pointer assignments to array operations ([github.com](https://github.com/nataliakzm/School42_Piscine?utm_source=chatgpt.com)):
- **ex00: ft_ft** – Assigns the value 42 to an integer through a pointer.
- **ex01: ft_ultimate_ft** – Assigns 42 using nested pointers (up to 17 levels deep).
- **ex02: ft_swap** – Swaps two integers by exchanging values via pointers.
- **ex03: ft_div_mod** – Calculates quotient and remainder from two integers and returns them via pointer parameters.
- **ex04: ft_ultimate_div_mod** – Applies division and modulus directly on the variables pointed to.
- **ex05: ft_putstr** – Writes a string to standard output using `write` and a custom `ft_putchar`.
- **ex06: ft_strlen** – Returns the length of a C-string by iterating until the null terminator.
- **ex07: ft_rev_int_tab** – Reverses the contents of an integer array in place.
- **ex08: ft_sort_int_tab** – Sorts an integer array in ascending order using a simple bubble-sort-like approach.

---

### ex00: ft_ft
**Prototype:**
```c
void ft_ft(int *nbr);
````

**Description:** Sets the value pointed to by `nbr` to 42. Always verify the pointer is non-NULL before dereferencing ([tane.harre.nz](https://tane.harre.nz/media/files/c01.pdf?utm_source=chatgpt.com)).

**Common Pitfalls:**

* Dereferencing a `NULL` pointer.
* Forgetting the `*` when assigning: use `*nbr = 42;` not `nbr = 42;`.

---

### ex01: ft\_ultimate\_ft

**Prototype:**

```c
void ft_ultimate_ft(int *********nbr);
```

**Description:** Traverses through multiple levels of pointers (up to 17) to ultimately set an integer to 42 ([gitlab.com](https://gitlab.com/piscine-421/piscine/c01?utm_source=chatgpt.com)).

**Tip:** Trace each `*` operator to ensure it correctly dereferences to the next level.

---

### ex02: ft\_swap

**Prototype:**

```c
void ft_swap(int *a, int *b);
```

**Description:** Exchanges the values of two integers pointed to by `a` and `b` by using a temporary variable ([gitlab.com](https://gitlab.com/piscine-421/piscine/c01?utm_source=chatgpt.com)).

**Best Practice:** Use a temporary variable (`int temp`) to hold one value during the swap:

```c
int temp = *a;
*a = *b;
*b = temp;
```

---

### ex03: ft\_div\_mod

**Prototype:**

```c
void ft_div_mod(int a, int b, int *div, int *mod);
```

**Description:** Divides `a` by `b`, storing the quotient at `*div` and the remainder at `*mod` ([teletype.in](https://teletype.in/%40udarcs/Yz117IvnPQB?utm_source=chatgpt.com)).

**Edge Cases:**

* Handle `b == 0` (division by zero) gracefully if required by extended specifications.

---

### ex04: ft\_ultimate\_div\_mod

**Prototype:**

```c
void ft_ultimate_div_mod(int *a, int *b);
```

**Description:** Performs division and modulus on the integers pointed by `a` and `b`, updating them in place: `*a` becomes the quotient and `*b` the remainder ([teletype.in](https://teletype.in/%40udarcs/Yz117IvnPQB?utm_source=chatgpt.com)).

---

### ex05: ft\_putstr

**Prototype:**

```c
void ft_putstr(char *str);
```

**Description:** Writes a null-terminated string to standard output by looping through each character and calling a `ft_putchar` wrapper around `write` ([github.com](https://github.com/7eith/Piscine42/blob/master/c01/ex05/main.ft_putstr.c?utm_source=chatgpt.com)).

**Tip:** Ensure to include the `write` system call: `write(1, &str[i], 1);`.

---

### ex06: ft\_strlen

**Prototype:**

```c
int ft_strlen(char *str);
```

**Description:** Returns the number of characters before the null terminator by incrementing a counter in a loop ([git.timo.one](https://git.timo.one/42berlin/piscine-c01/blame/commit/dac1929e9386e9f4c54d768ade4a788b5ead4ae5/ex06/ft_strlen.c?utm_source=chatgpt.com)).

**Implementation Outline:**

```c
int ft_strlen(char *str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}
```

---

### ex07: ft\_rev\_int\_tab

**Prototype:**

```c
void ft_rev_int_tab(int *tab, int size);
```

**Description:** Reverses an integer array by first storing a copy in a temporary array and then copying back in reverse order ([git.hexanyn.fr](https://git.hexanyn.fr/42/piscine/c01/-/blob/master/ex07/ft_rev_int_tab.c?utm_source=chatgpt.com)).

**Key Steps:**

1. Create a temporary buffer `int tmp[size]`.
2. Copy elements from `tab` in reverse into `tmp`.
3. Overwrite `tab` with `tmp` contents.

---

### ex08: ft\_sort\_int\_tab

**Prototype:**

```c
void ft_sort_int_tab(int *tab, int size);
```

**Description:** Sorts an integer array in ascending order using a simple comparative swap loop (similar to bubble sort) ([github.com](https://github.com/rossattism/42.Piscine/blob/master/c01/ex08/ft_sort_int_tab.c?utm_source=chatgpt.com)).

**Algorithm Sketch:**

1. Loop `i` from 0 to `size-2`.
2. Loop `j` from `i+1` to `size-1`.
3. If `tab[i] > tab[j]`, swap them and reset `i` to 0 to ensure full sorting pass.

---

**Submission Tips:**

* Submit only the required `.c` files with correct names.
* Ensure all code compiles with `-Wall -Wextra -Werror`.
* Pass the Norminette style checker without forbidden functions.

**Further Reading & Resources:**

* **Pointers in C:** [GeeksforGeeks Pointers Tutorial](https://www.geeksforgeeks.org/pointers-in-c-and-their-usage/) (accessed 2025).
* **String Functions:** [C Standard Library `strlen`](https://en.cppreference.com/w/c/string/byte/strlen) (accessed 2025).

```
```
