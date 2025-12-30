#ifndef DICTIONARY_ATTACK_H
#define DICTIONARY_ATTACK_H

#include "types.h"

bool dictionary_attack(
    const string& target_hash,
    HashType hash_type,
    const string& wordlist_path,
    string& result
);

#endif
