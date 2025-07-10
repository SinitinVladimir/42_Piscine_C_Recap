````markdown
# Shell01 Cheat Sheet

**Summary:**  
Shell01 deepens your POSIX shell skills with environment variables, file discovery, text parsing, and arithmetic.

---

## Prerequisites & Environment

- **Shell Interpreter:** `#!/bin/sh` (POSIX-compliant) or Bash in POSIX mode.  
- **Make Executable:** `chmod +x script_name.sh`.  
- **Environment Variables Used:**  
  - `FT_USER` (fallback to `$USER`)  
  - `FT_LINE1`, `FT_LINE2`  
  - `FT_NBR1`, `FT_NBR2`  
- **Optional Strict Mode (Bash-only):**
  ```sh
  set -euo pipefail
````

---

## Exercise Index

| Ex | Script Name         | Description                                                          |
| -- | ------------------- | -------------------------------------------------------------------- |
| 00 | `exam_machine`      | Print system/machine information                                     |
| 01 | `print_groups`      | List groups of `$FT_USER` or `$USER`, comma-separated                |
| 02 | `find_sh`           | Find `.sh` files up to one subdirectory, append `$`                  |
| 03 | `count_files`       | Count `.sh` files in current directory                               |
| 04 | `MAC`               | Display MAC addresses of all interfaces                              |
| 05 | `can_you_create_it` | List and cat a file whose name contains special chars                |
| 06 | `skip`              | List only odd-numbered `ex0N*/` directories                          |
| 07 | `r_dwssap`          | Reverse names `exN` for N in `$FT_LINE1..$FT_LINE2` joined by commas |
| 08 | `add_chelou`        | Sum two escaped hex numbers stored in `$FT_NBR1`, `$FT_NBR2`         |

---

## Detailed Solutions

### 00 `exam_machine`

Print full kernel and machine info:

```sh
#!/bin/sh
uname -a
```

* Outputs kernel name, hostname, OS, architecture, etc.

### 01 `print_groups`

List groups for `$FT_USER` (or `$USER`):

```sh
#!/bin/sh
user=${FT_USER:-$USER}
id -Gn "$user" | tr ' ' ','
```

* `id -Gn` prints group names, `tr` replaces spaces with commas.

### 02 `find_sh`

Locate `.sh` scripts (max depth 2), print names ending with `$`:

```sh
#!/bin/sh
find . -maxdepth 2 -type f -name '*.sh' \
  -printf '%f$\n'
```

* `%f` prints filename only, append `$`, newline.

### 03 `count_files`

Count `.sh` files in the current directory:

```sh
#!/bin/sh
find . -maxdepth 1 -type f -name '*.sh' | wc -l
```

* `wc -l` counts lines (number of files).

### 04 `MAC`

Extract MAC addresses from interfaces:

```sh
#!/bin/sh
ifconfig -a 2>/dev/null | grep -Eo '([[:xdigit:]]{2}:){5}[[:xdigit:]]{2}'
```

* Redirect stderr to `/dev/null` if `ifconfig` unavailable.

### 05 `can_you_create_it`

Handle filenames with special characters:

```sh
#!/bin/sh
ls -l
cat "\\?\\$*'MaRViN'*\\$?\\"
```

* Quote path, backslash-escape `?`, `$`, `*`, and quotes.

### 06 `skip`

List only odd-numbered exercise directories:

```sh
#!/bin/sh
ls -d ex0[1357]*/
```

* Matches `ex01`, `ex03`, `ex05`, `ex07`, `ex09`.

### 07 `r_dwssap`

Reverse `exN` names for N in range, join with commas:

```sh
#!/bin/sh
seq "$FT_LINE1" "$FT_LINE2" \
  | xargs -I{} echo "ex{}" \
  | rev \
  | paste -sd ',' -
```

* `seq` for numbers, `xargs` builds names, `rev` reverses, `paste` joins.

### 08 `add_chelou`

Sum two hex numbers stored with escapes:

```sh
#!/bin/sh
n1=$(echo "$FT_NBR1" | tr -d "'*\\?")
n2=$(echo "$FT_NBR2" | tr -d "'*\\?")
echo "ibase=16; $n1 + $n2" | bc
```

* `tr -d` strips escape chars; `bc` computes hex addition.

---

## POSIX Compliance & Best Practices

* **Shebang:** Use `#!/bin/sh` at script top.
* **Executable:** `chmod +x script.sh`.
* **Quoting/Escaping:** Wrap variables and paths in `""`; escape special chars.
* **Exit Codes:** Use `exit 0` for success, `exit 1` for failures.
* **Env Checks:** Validate required vars:

  ```sh
  [ -n "$FT_USER" ] || exit 1
  ```
* **Error Handling:** Redirect or handle command failures:

  ```sh
  ifconfig -a 2>/dev/null || true
  ```

---

**The end**

```
```
