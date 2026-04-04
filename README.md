## CTF Hash Cracker
 
CTF Hash Cracker is a **command-line interface (CLI) tool written in C++** designed to **automatically detect cryptographic hash types** and perform **dictionary-based attacks**.  
This project is intended for **Capture The Flag (CTF) challenges, cryptography education, and introductory security research**.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

---

## 📋 Table of Contents

- [Features](#-features)
- [Project Structure](#-project-structure)
- [Prerequisites](#-prerequisites)
- [Installation & Build](#-installation--build)
- [Usage](#-usage)
- [Examples](#-examples)
- [Additional Documentation](#-additional-documentation)
- [Contributing](#-contributing)
- [License](#-license)
- [Disclaimer](#-disclaimer)

---

## ✨ Features

- ✅ **Automatic detection** of hash types (MD5, SHA1, SHA256)
- ✅ **Dictionary attack** with progress indicator
- ✅ Support for **custom wordlists**
- ✅ **Export results** to file
- ✅ Fast and lightweight
- ✅ Cross-platform (Windows MSYS2, Linux, macOS)

---

## 📂 Project Structure

```
ctf-hash-cracker/
│
├── src/
│   ├── main.cpp                 # Application entry point
│   ├── hash_detector.cpp        # Automatic hash type detection
│   ├── hasher.cpp               # Hash computation (MD5, SHA1, SHA256)
│   ├── dictionary_attack.cpp    # Dictionary attack implementation
│   ├── rules.cpp                # Transformation rules (placeholder)
│   └── utils.cpp                # Utility/helper functions (placeholder)
│
├── include/
│   ├── hash_detector.h
│   ├── hasher.h
│   ├── dictionary_attack.h
│   ├── hash_types.h
│   ├── rules.h
│   └── utils.h
│
├── wordlists/
│   └── common.txt               # Default wordlist
│
├── tests/
│   └── test_hashes.cpp          # Unit tests (optional)
│
├── build/                       # Build artifacts (generated)
├── CMakeLists.txt               # CMake configuration
├── README.md                    # This file
├── DISCLAIMER.md                # Legal disclaimer
├── threat_model.md              # Security threat model
├── LICENSE                      # MIT License
└── .gitignore                   # Git ignore rules
```

---

##  Prerequisites

### Windows (MSYS2 MinGW64)
- **MSYS2** with MinGW64 toolchain
- **CMake** (version 3.16 or higher)
- **Ninja** build system
- **OpenSSL** development libraries

Install dependencies in MSYS2 MinGW64 terminal:
```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja mingw-w64-x86_64-openssl
```

### Linux
```bash
# Debian/Ubuntu
sudo apt install build-essential cmake ninja-build libssl-dev

# Fedora/RHEL
sudo dnf install gcc-c++ cmake ninja-build openssl-devel

# Arch Linux
sudo pacman -S base-devel cmake ninja openssl
```

### macOS
```bash
brew install cmake ninja openssl
```

---

##  Installation & Build

### Clone the Repository
```bash
git clone https://github.com/candra2006/ctf_hash.git
cd ctf_hash
```

### Build Instructions (Windows – MSYS2 MinGW64)

**Important:** Use the **MSYS2 MinGW64** terminal (not UCRT or MSYS).

```bash
mkdir build
cd build
cmake -G Ninja ..
ninja
```

### Build Instructions (Linux/macOS)
```bash
mkdir build
cd build
cmake ..
make
```

The compiled binary will be located in the `build/` directory.

---

##  Usage

### Basic Syntax
```bash
./ctf-cracker <HASH> <WORDLIST> [options]
```

### Options
- `-h, --help` — Display help message
- `--out <file>` — Save cracked password to specified file

### Help Command
```bash
./ctf-cracker --help
```

---

##  Examples

### Example 1: Crack MD5 Hash
```bash
./ctf-cracker 5f4dcc3b5aa765d61d8327deb882cf99 ../wordlists/common.txt
```

**Output:**
```
[+] Hash Type: MD5
[+] Tried 1000 passwords...
[+] Password found after 3 attempts
[+] Password: password
```

### Example 2: Crack SHA256 Hash with Output File
```bash
./ctf-cracker e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855 ../wordlists/common.txt --out result.txt
```

### Example 3: Using Custom Wordlist
```bash
./ctf-cracker 356a192b7913b04c54574d18c28d46e6395428ab /path/to/custom/wordlist.txt
```

### Supported Hash Types
| Hash Type | Length (hex) | Example |
|-----------|-------------|---------|
| MD5       | 32 chars    | `5f4dcc3b5aa765d61d8327deb882cf99` |
| SHA1      | 40 chars    | `356a192b7913b04c54574d18c28d46e6395428ab` |
| SHA256    | 64 chars    | `e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855` |

---

## 📚 Additional Documentation
- **[LICENSE](LICENSE)** — MIT License details

---

## 🤝 Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## ⚠️ Disclaimer

**This tool is intended for educational purposes, Capture The Flag (CTF) competitions, and authorized security testing only.**

**Unauthorized access to computer systems is illegal.** Users are responsible for ensuring they have proper authorization before using this tool. The developers assume no liability for misuse or damage caused by this software.

---

## 👨‍💻 Author

**Candra**
---
