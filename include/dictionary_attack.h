#ifndef DICTIONARY_ATTACK_H
#define DICTIONARY_ATTACK_H

#include <string>
#include "hash_types.h"

bool dictionary_attack(
    const std::string& target_hash,
    const std::string& wordlist_path,
    HashType hash_type,
    std::string& result
);

#endif
