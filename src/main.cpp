#include <iostream>
#include <string>
#include <fstream>

#include "hash_detector.h"
#include "dictionary_attack.h"

using std::cout;
using std::endl;
using std::string;

void print_help() {
    cout << "CTF Hash Cracker\n\n";
    cout << "Usage:\n";
    cout << "  ctf-cracker <HASH> <WORDLIST> [options]\n\n";
    cout << "Options:\n";
    cout << "  -h, --help           Show this help message\n";
    cout << "  --out <file>         Save cracked password to file\n\n";
    cout << "Example:\n";
    cout << "  ctf-cracker 5f4dcc3b5aa765d61d8327deb882cf99 wordlist.txt --out result.txt\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_help();
        return 0;
    }

    string arg1 = argv[1];
    if (arg1 == "-h" || arg1 == "--help") {
        print_help();
        return 0;
    }

    if (argc < 3) {
        cout << "[-] Missing arguments\n";
        print_help();
        return 1;
    }

    string target_hash   = argv[1];
    string wordlist_path = argv[2];
    string output_file   = "";

    // parse optional args
    for (int i = 3; i < argc; i++) {
        if (string(argv[i]) == "--out" && i + 1 < argc) {
            output_file = argv[i + 1];
            i++;
        }
    }

    HashType type = detect_hash_type(target_hash);
    if (type == HASH_UNKNOWN) {
        cout << "[-] Unknown hash type\n";
        return 1;
    }

    cout << "[+] Hash Type: " << hash_type_to_string(type) << endl;

    string result;
    if (dictionary_attack(target_hash, wordlist_path, type, result)) {
        cout << "[+] Password: " << result << endl;

        if (!output_file.empty()) {
            std::ofstream out(output_file);
            if (out.is_open()) {
                out << "Hash: " << target_hash << endl;
                out << "Type: " << hash_type_to_string(type) << endl;
                out << "Password: " << result << endl;
                out.close();
                cout << "[+] Saved to file: " << output_file << endl;
            } else {
                cout << "[-] Failed to write output file\n";
            }
        }
    } else {
        cout << "[-] Password not found\n";
    }

    return 0;
}
