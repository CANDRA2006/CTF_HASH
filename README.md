# CTF Hash Cracker

CTF Hash Cracker is a **command-line interface (CLI) tool written in C++** designed to **automatically detect cryptographic hash types** and perform **dictionary-based attacks**.  
This project is intended for **Capture The Flag (CTF) challenges, cryptography education, and introductory security research**.

---

## Project Structure

```
│
├── src/
│ ├── main.cpp # Application entry point
│ ├── hash_detector.cpp # Automatic hash type detection
│ ├── hasher.cpp # Hash computation (MD5, SHA1, SHA256)
│ ├── dictionary_attack.cpp # Dictionary attack implementation
│ ├── rules.cpp # Transformation rules (if applicable)
│ ├── utils.cpp # Utility/helper functions
│ └── output/ # Automatically generated output files
│
├── include/
│ ├── hash_detector.h
│ ├── hasher.h
│ ├── dictionary_attack.h
│ ├── rules.h
│ └── utils.h
│
├── wordlists/
│ └── common.txt # Default wordlist
│
├── tests/
│ └── test_hashes.cpp # Unit tests (optional)
│
├── build/ # Build artifacts (generated)
├── CMakeLists.txt
├── README.md
├── LICENSE
└── threat_model.md
```


---

## Build Instructions (Windows – MSYS2 MinGW64)

Ensure that the project is built using **MSYS2 MinGW64** (not UCRT or the standard MSYS shell).

```bash
cd /c/Users/YourName/path/to/ctf-hash-craker
mkdir build
cd build
cmake -G Ninja ..
ninja
