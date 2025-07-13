# mini moluinete and norminette setup on Windows 10 - 11 in git bash 
set -e

info() { echo -e "[INFO] $*"; }
error() { echo -e "[ERROR] $*" >&2; exit 1; }

# 1. Chocolatey
info "Checking for Chocolatey..."
if ! command -v choco >/dev/null 2>&1; then
  info "Installing Chocolatey..."
  powershell.exe -NoProfile -InputFormat None -ExecutionPolicy Bypass \
    -Command "Set-ExecutionPolicy Bypass -Scope Process; \
      [System.Net.ServicePointManager]::SecurityProtocol = \
      [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; \
      iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))"
else
  info "Chocolatey already installed."
fi

# 2. Git
info "Checking for Git..."
if ! command -v git >/dev/null 2>&1; then
  info "Installing Git..."
  choco install git.install -y
else
  info "Git already installed."
fi

# 3. Python 3.10+
info "Checking for Python 3.10+..."
if ! command -v python >/dev/null 2>&1 || \
   ! python -c 'import sys; exit(0 if sys.version_info >= (3,10) else 1)' ; then
  info "Installing Python..."
  choco install python -y
else
  info "Python 3.10+ already installed: $(python --version 2>&1)"
fi

# 4. pip
info "Ensuring pip is available..."
if ! python -m pip --version >/dev/null 2>&1; then
  info "Bootstrapping pip..."
  python -m ensurepip --upgrade
else
  info "pip is available."
fi

# 5. norminette
info "Installing/Upgrading Norminette..."
python -m pip install --user --upgrade pip setuptools norminette

# 6. Get the user scripts path in UNIX format (auto-detects version and user)
PYUSERBASE="$(python -c 'import site; print(site.USER_BASE)')"
WIN_SCRIPT_PATH="${PYUSERBASE}\\Scripts"
UNIX_SCRIPT_PATH="$(cygpath -u "$WIN_SCRIPT_PATH")"

# 7. Setup shell profiles
for PROFILE in ~/.bashrc ~/.bash_profile; do
  [ -f "$PROFILE" ] || touch "$PROFILE"
  # Remove old similar lines
  sed -i '/Python.*Scripts/d;/norminette/d;/mini-moulinette/d;/alias mini/d' "$PROFILE"
  # Add the correct PATH line if missing
  grep -F "$UNIX_SCRIPT_PATH" "$PROFILE" >/dev/null || \
    echo "export PATH=\"$UNIX_SCRIPT_PATH:\$PATH\"" >> "$PROFILE"
  # Add mini alias
  grep -F 'alias mini=' "$PROFILE" >/dev/null || \
    echo "alias mini=\"bash \$HOME/mini-moulinette/mini-moul.sh\"" >> "$PROFILE"
done

# 8. Mini-Moulinette setup
info "Setting up Mini-Moulinette..."
if [ ! -d "$HOME/mini-moulinette" ]; then
  git clone https://github.com/khairulhaaziq/mini-moulinette.git "$HOME/mini-moulinette"
fi
chmod +x "$HOME/mini-moulinette/mini-moul.sh"

# 9. Source updated profile
info "Activating updated PATH and aliases for this session..."
source ~/.bashrc || source ~/.bash_profile

# 10. Verify installs
info "Verifying Norminette..."
if ! command -v norminette >/dev/null; then
  error "Norminette not found on PATH! Try restarting Git Bash, or check your Python user install."
fi

info "Verifying mini alias..."
if ! command -v mini >/dev/null; then
  error "Mini-moulinette alias not found! Check your ~/.bashrc."
fi

echo
echo "🎉 Setup complete! Usage examples:"
echo "  norminette           # Check all C/H files for 42 style"
echo "  norminette --version # Check Norminette version"
echo "  cd ~/42_Piscine_C_Recap/C01 && mini   # Run Mini-Moulinette tests (inside a Cxx folder)"
echo
echo "If you open a new Git Bash window, both commands should always work."
