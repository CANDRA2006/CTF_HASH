#include "dictionary_attack.h"
#include "hasher.h"

#include <fstream>
#include <iostream>

using std::string;

bool dictionary_attack(
    const string& target_hash,
    const string& wordlist_path,
    HashType hash_type,
    string& result
) {
    std::ifstream file(wordlist_path);
    if (!file.is_open()) {
        std::cerr << "[-] Cannot open wordlist file\n";
        return false;
    }

    // cek wordlist kosong
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "[-] Wordlist is empty\n";
        return false;
    }

    string line;
    size_t count = 0;

    while (std::getline(file, line)) {
        count++;

        string hashed = hash_string(line, hash_type);
        if (hashed == target_hash) {
            std::cout << "\n[+] Password found after " << count << " attempts\n";
            result = line;
            return true;
        }

        // progress bar sederhana
        if (count % 1000 == 0) {
            std::cout << "\r[+] Tried " << count << " passwords..." << std::flush;
        }
    }

    std::cout << "\n[-] Finished " << count << " attempts\n";
    return false;
}
