#include "hash_detector.h"

HashType detect_hash_type(const std::string& hash) {
    if (hash.length() == 32) return HASH_MD5;
    if (hash.length() == 40) return HASH_SHA1;
    if (hash.length() == 64) return HASH_SHA256;
    return HASH_UNKNOWN;
}

std::string hash_type_to_string(HashType type) {
    switch (type) {
        case HASH_MD5:    return "MD5";
        case HASH_SHA1:   return "SHA1";
        case HASH_SHA256: return "SHA256";
        default:          return "UNKNOWN";
    }
}
