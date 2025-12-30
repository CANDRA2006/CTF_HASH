#include <iostream>
#include "hash_detector.h"
#include "dictionary_attack.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: ctf-cracker <hash> <wordlist>\n";
        return 1;
    }

    string target_hash = argv[1];
    string wordlist = argv[2];

    HashType type = detect_hash_type(target_hash);

    if (type == HASH_UNKNOWN) {
        cout << "[-] Unknown hash type\n";
        return 1;
    }

    cout << "[+] Hash Type: " << hash_type_to_string(type) << endl;

    string result;
    if (dictionary_attack(target_hash, type, wordlist, result)) {
        cout << "[+] Password Found: " << result << endl;
    } else {
        cout << "[-] Password Not Found\n";
    }

    return 0;
}
