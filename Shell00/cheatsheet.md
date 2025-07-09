# Shell00 Cheat Sheet


## Exercise Index

| Ex | Name                       | Command(s)                                              |
| -- | -------------------------- | ------------------------------------------------------- |
| 00 | **Z**                      | `echo Z`                                                |
| 01 | **testShell00**            | `echo "testShell00"`                                    |
| 02 | **Oh yeah, mooore…**       | `grep 'pattern' filename.txt`                           |
| 03 | **Connect me!**            | `ssh user@remote.host`                                  |
| 04 | **midLS**                  | `ls -la --sort=time`                                    |
| 05 | **GiT commit**             | `git init && git add . && git commit -m "first commit"` |
| 06 | **gitignore**              | Create `.gitignore` with glob patterns                  |
| 07 | **diff**                   | `diff -u old.txt new.txt`                               |
| 08 | **clean**                  | `rm -f *.o && rm -rf build/`                            |
| 09 | **Illusions, not tricks…** | `echo $#`, `echo "$1"`, `echo "${!#}"`                  |

---

## Detailed Solutions

### 00 Z

Print exactly `Z` to stdout.

```sh
#!/bin/sh
echo Z
```

### 01 testShell00

Output the literal string `testShell00`.

```sh
echo "testShell00"
```

### 02 Oh yeah, mooore…

Filter lines containing `mooore` in a file.

```sh
grep 'mooore' filename.txt
```

### 03 Connect me!

Securely log into a remote host via SSH.

```sh
ssh user@remote.host
```

### 04 midLS

List all files (including hidden), long format, sorted by modification time.

```sh
ls -la --sort=time
```

### 05 GiT commit

Initialize, stage, and commit in Git.

```sh
git init
git add .
git commit -m "first commit"
```

### 06 gitignore

Ignore build artifacts or temporary files. Create `.gitignore` in repo root:

```gitignore
*.log
*.tmp
build/
```

### 07 diff

Show unified diff between two files.

```sh
diff -u old.txt new.txt
```

### 08 clean

Remove object files and build directory.

```sh
rm -f *.o
rm -rf build/
```

### 09 Illusions, not tricks…

Inspect script arguments.

```sh
echo "Argument count: $#"
echo "First argument: $1"
echo "Last argument: ${!#}"
```

---

## POSIX Compliance & Best Practices

* **Shebang & Permissions**: Always start with `#!/bin/sh` and `chmod +x script.sh`.
* **Strict Mode** (Bash-only):

  ```sh
  set -euo pipefail
  ```
* **Argument Validation**: Check `$#` and display a usage message if incorrect.
* **Moulinette Compliance**: Match exact filenames, output format, and exit codes (`0` for success).
* **Testing**: Test scripts with no args, one arg, special characters, and empty files.

---

## 🔑 10 Most Useful Shell Commands

1. **ls** – list directory contents

   ```sh
   ls -lh /etc
   ```
2. **cd** – change directory

   ```sh
   cd ~/projects
   ```
3. **pwd** – print working directory

   ```sh
   pwd
   ```
4. **grep** – search text patterns

   ```sh
   grep -R "TODO" src/
   ```
5. **find** – locate files

   ```sh
   find . -name "*.sh" -type f
   ```
6. **awk** – text processing

   ```sh
   ps aux | awk '{print $1, $2}'
   ```
7. **sed** – stream editing

   ```sh
   sed -n '1,5p' file.txt
   ```
8. **tar** – archive/unarchive

   ```sh
   tar czvf archive.tar.gz ./folder
   ```
9. **chmod** – change permissions

   ```sh
   chmod 755 script.sh
   ```
10. **ps** – list processes

```sh
ps aux | grep sshd
```
