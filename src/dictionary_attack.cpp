#include "dictionary_attack.h"
#include "hasher.h"
#include <fstream>

using namespace std;

bool dictionary_attack(
    const string& target_hash,
    HashType hash_type,
    const string& wordlist_path,
    string& result
) {
    ifstream file(wordlist_path);
    if (!file.is_open()) {
        return false;
    }

    string line;
    while (getline(file, line)) {
        string hashed = hash_string(line, hash_type);
        if (hashed == target_hash) {
            result = line;
            return true;
        }
    }

    return false;
}
