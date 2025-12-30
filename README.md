## COMING SOON

# CTF Hash Cracker

A simple C++ hash cracking tool for Capture The Flag (CTF) challenges.
Supports dictionary attacks for common hash types using OpenSSL.

## Features
- Hash type auto-detection
- Dictionary attack
- OpenSSL-based hashing
- Clean modular C++ design

## Supported Hashes
- MD5
- SHA1
- SHA256

## Build (Windows - MinGW + Ninja)

```bash
mkdir build
cd build
cmake -G Ninja ..
ninja
